#include"apue.h"
#define  R  1   //  user register注册
#define  L  2   //  user login 登陆
#define  Q  3   //  query word 查单词
#define  H  4   //  history record  查询历史记录
#define  E   5  //退出
#define N 20
typedef struct 
{
	int type;//命令的类型
	char name[N];//用户名
	char data[1024];   // password or word 存放密码或单词信息、服务器端回馈信息
} MSG;


sqlite3*db = NULL;


//退出功能
void deal_exit(int newconfd,MSG *pbuf)
{
	//封包 
	strcpy(pbuf->data,"退出成功");

	//发送给客户端
	write(newconfd,pbuf,sizeof(MSG));
}


//注册功能
void deal_register(int newconfd,MSG *pbuf)
{
	//数据库查询是否已经存在该用户

	char sql[100]="\0";
	char *errmsg = NULL;
	char **result = NULL;
	int row;
	int col;

	//拼接
	sprintf(sql,"select *from usr_info where name='%s'",pbuf->name);
	if(sqlite3_get_table(db,sql,&result,&row,&col,&errmsg))
	{
		printf("register:%s\n",errmsg);
		return;
	}

	//如果不存在  将信息插入用户信息表并回复登录成功
	if(0==row)
	{
		//注册 
		bzero(sql,sizeof(sql));
		sprintf(sql,"insert into usr_info values('%s',%s)",pbuf->name,pbuf->data);
		if(sqlite3_exec(db,sql,NULL,NULL,&errmsg))
		{
			printf("register-gettable:%s\n",errmsg);
			return;

		}
		//回复客户端
		strcpy(pbuf->data,"注册成功");
	}
	else //如果已存在 则回复注册失败
	{
		strcpy(pbuf->data,"注册失败");
	}

	//将数据包写给客户端
	write(newconfd,pbuf,sizeof(MSG));

	sqlite3_free_table(result);


}


//登录功能
void deal_log(int newconfd,MSG *pbuf)
{
	//数据库查询  
	char **result=NULL;
	int row;
	int col;
	char *errmsg=NULL;
	char sql[100]="\0";
	sprintf(sql,"select *from usr_info where name='%s' and password=%s",pbuf->name,pbuf->data);
	if(sqlite3_get_table(db,sql,&result,&row,&col,&errmsg))
	{
		printf("login gettable:%s\n",errmsg);
		return;
	}
	if(row)
	{
		//用户名密码都匹配 
		strcpy(pbuf->data,"登录成功");
	}
	else 
	{

		strcpy(pbuf->data,"登录失败");
	}

	//将数据写回客户端
	write(newconfd,pbuf,sizeof(MSG));

	sqlite3_free_table(result);

}

//查找单词
int search_word(MSG *pbuf)
{
	int ret;
	char line[500]="\0";
	//打开词典文件
	FILE *fp = fopen("dict.txt","r");
	if(NULL==fp)
	{
		perror("fopen");
		return -1;
	}

	//获取单词长度
	size_t len = strlen(pbuf->data);

	//从词典文件中按行读取
	while(fgets(line,sizeof(line),fp)!=NULL)
	{
		ret = strncmp(pbuf->data,line,len);	
		if(ret>0)//要查的单词在下边
		{
			continue;
		}
		else if(ret<0||line[len]!=' ')
		{
			return 0;//没查到单词
		}
		else//查到单词 
		{
			//将单词解释获取
			strcpy(pbuf->data,line);
			return 1;
		}
		bzero(line,sizeof(line));
	}
}
//查询单词并处理历史记录
void deal_dic(int newconfd,MSG *pbuf)
{
	char word[50]="\0";
	char sql[100]="\0";
	char *errmsg=NULL;
	time_t t;
	char get_time[100]="\0";
	size_t len;
	//保存要查询的单词
	strcpy(word,pbuf->data);

	//查询单词
	//ret 1 说明查到了  0 说明没查到
	int ret = search_word(pbuf);//pbuf->data
	if(ret)
	{
		//获取当前系统时间
		t = time(NULL);
		strcpy(get_time,ctime(&t));

		//ctime获取的时间末尾自动加\n 所以要覆盖\n
		//12345\n
		len = strlen(get_time);
		get_time[len-1] = '\0';//用'\0'覆盖'\n'

		//将用户名 时间 查的单词 插入历史记录表
		sprintf(sql,"insert into history_info values('%s','%s','%s')",pbuf->name,get_time,word);
		if(sqlite3_exec(db,sql,NULL,NULL,&errmsg))
		{
			printf("query dic:%s\n",errmsg);
			return;
		}
	}
	else 
	{
		strcpy(pbuf->data,"单词不存在");
	}

	//将查询结果回发给客户端
	write(newconfd,pbuf,sizeof(MSG));

}

/************************************************
 *           查询历史记录
 * **********************************************/

void deal_history(int connfd, MSG *pbuf)
{

	char  **result;
	int nrow, ncolumn;
	int i;
	char sqlstr[1024]="\0";

	//查询历史记录
	sprintf(sqlstr, "select *from history_info where name = '%s'", pbuf->name);

	if (sqlite3_get_table(db, sqlstr, &result, &nrow, &ncolumn,NULL))
	{
		printf("history get table:%s\n",sqlite3_errmsg(db));
		exit(-1);
	}

	//将查询到的结果回发给客户端
	if(nrow!=0)
	{

		for(i=0;i<(nrow+1)*ncolumn;i++)
		{

			sprintf(pbuf->data,"%s",result[i]);			
			write(connfd, pbuf, sizeof(MSG));
				
			bzero(pbuf->data,sizeof(pbuf->data));
			//bzero(pbuf,sizeof(MSG));
			usleep(1);//延时发送
		}

	}

	//发送给客户端
	strcpy(pbuf->data,"end");
	write(connfd, pbuf, sizeof(MSG));

}
//子线程
void *deal_client(void *p)
{
	MSG buf;
	ssize_t ret;
	int newconfd = *(int*)p;

	//将线程设置为分离属性
	pthread_detach(pthread_self());

	//循环读取客户端的数据包
	while((ret = read(newconfd,&buf,sizeof(buf)))>0)//ret <0 出错    ret==0 对方close
	{
		//解析数据包
		switch(buf.type)
		{
		case R:
			deal_register(newconfd,&buf);
			break;
		case L:
			deal_log(newconfd,&buf);
			break;
		case E:
			deal_exit(newconfd,&buf);
			break;
		case Q:
			deal_dic(newconfd,&buf);
			break;
		case H:
			deal_history(newconfd,&buf);
			break;
		default:
			puts("error");
			break;
		}

	}

	close(newconfd);
	return NULL;
}

//./s ip port
int main(int argc,char*argv[])
{
	if(argc!=3)
	{
		printf("%s 本机ip 本机端口\n",argv[0]);
		exit(-1);
	}

	pthread_t tid;
	char *errmsg = NULL;
	int newconfd,ret;

	//1.创建数据库
	if(sqlite3_open("data.db",&db))
	{
		printf("%s\n",sqlite3_errmsg(db));
		exit(0);
	}

	//2.创建用户信息表及历史记录表
	char *sql="create table if not exists usr_info(name varchar(20),password integer)";
	if(sqlite3_exec(db,sql,NULL,NULL,&errmsg))
	{
		printf("sqlite3_exec usr_info:%s\n",errmsg);
		sqlite3_close(db);
		exit(-1);
	}

	char *sql1="create table if not exists history_info(name varchar,time varchar(20),word varchar(20))";
	if(sqlite3_exec(db,sql1,NULL,NULL,&errmsg))
	{
		printf("sqlite3_exec history__info:%s\n",errmsg);
		sqlite3_close(db);
		exit(-1);
	}

	//3.多线程并发服务器
	int listenfd = socket(AF_INET,SOCK_STREAM,0);
	if(listenfd<0)
	{
		perror("socket");
		sqlite3_close(db);
		exit(-1);
	}

	struct sockaddr_in selfaddr;
	selfaddr.sin_family = AF_INET;
	selfaddr.sin_port = htons(atoi(argv[2]));
	selfaddr.sin_addr.s_addr = inet_addr(argv[1]);
	if(bind(listenfd,(struct sockaddr*)&selfaddr,sizeof(selfaddr))<0)
	{
		perror("bind");
		close(listenfd);
		sqlite3_close(db);
		exit(-1);
	}

	if(listen(listenfd,10)<0)
	{
		perror("listen");
		close(listenfd);
		sqlite3_close(db);
		exit(-1);
	}

	while(1)
	{
		//连接客户端
		if((newconfd = accept(listenfd,NULL,NULL))<0)
		{
			perror("bind");
			close(listenfd);
			sqlite3_close(db);
			exit(-1);
		}

		//创建子线程服务客户端
		if((ret = pthread_create(&tid,NULL,deal_client,&newconfd))<0)
		{
			printf("pthread_create:%s\n",strerror(ret));
		}
	}

	return 0;
}

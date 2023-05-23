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


void deal_exit(int sockfd,MSG *pbuf)
{
	//封包 
	pbuf->type = E;

	//发送给服务器
	write(sockfd,pbuf,sizeof(MSG));

	//接收服务器回发的处理结果
	bzero(pbuf,sizeof(MSG));
	read(sockfd,pbuf,sizeof(MSG));

	//显示
	printf("%s\n",pbuf->data);
}

//注册功能
void deal_register(int sockfd,MSG *pbuf)
{
	//封包 
	pbuf->type = R;

	puts("请输入 用户名 密码");
	scanf("%s%s",pbuf->name,pbuf->data);

	//发送服务器
	write(sockfd,pbuf,sizeof(MSG));

	//接收数据包
	bzero(pbuf,sizeof(MSG));
	read(sockfd,pbuf,sizeof(MSG));
	puts(pbuf->data);
	
}

//登录功能
int  deal_log(int sockfd,MSG *pbuf)
{

	//封包 
	pbuf->type = L;

	puts("请输入 用户名 密码");
	scanf("%s%s",pbuf->name,pbuf->data);

	

	//将数据包发送给服务器
	write(sockfd,pbuf,sizeof(MSG));
	//接收服务器返回的处理结果
	bzero(pbuf,sizeof(MSG));
	read(sockfd,pbuf,sizeof(MSG));
	puts(pbuf->data);
	
	//如果登录成功 return 1 否则return 0
	if(!strcmp(pbuf->data,"登录成功"))
	{
		return 1;
	}
	else 
	{
		return 0;
	}
	
}

void query_dic(int sockfd,MSG *pbuf)
{
	//封包 

	while(1)
	{
		pbuf->type = Q;
		//键盘获取单词
		puts("请输入想要查询的单词(按#结束)");
		scanf("%s",pbuf->data);
		if(!strcmp(pbuf->data,"#"))
		{
			break;
		}

		//发送给服务器 
		write(sockfd,pbuf,sizeof(MSG));

		//接收服务器回发的处理结果
		bzero(pbuf,sizeof(MSG));
		read(sockfd,pbuf,sizeof(MSG));
		puts(pbuf->data);

		bzero(pbuf->data,sizeof(pbuf->data));
	}

}

/*************************************
  查历史记录
 *************************************/
void query_history(int sockfd, MSG *pbuf)
{
	int i=0;
	pbuf->type = H;
	write(sockfd, pbuf, sizeof(MSG));

	//循环读取服务器查询到的
	while(1)
	{
		i++;
		bzero(pbuf,sizeof(MSG));
		read(sockfd, pbuf, sizeof(MSG));

		if (!strcmp(pbuf->data,"end")) //说明服务器发送数据完毕
		{
			break;
		}
		printf("%40s", pbuf->data);//%2d
		if(i%3==0)
		{
			printf("\n");
		} 	

	}

}


//二级菜单
void deal_dic_history(int sockfd,MSG *pbuf)
{
	int choose;
	while(1)
	{
		puts("*************************************");
		puts("  1. 查单词    2.查历史记录    3.退出");
		puts("**************************************");
		scanf("%d",&choose);

		switch(choose)
		{
			case 1:
				query_dic(sockfd,pbuf);
				break;
			case 2:
				query_history(sockfd,pbuf);
				break;
		    case 3:
				deal_exit(sockfd,pbuf);
				close(sockfd);
				exit(0);
				break;
			default:
				puts("choose error");
				break;

		}

		sleep(1);
		system("clear");
	}
}
void menu(int sockfd)
{
	int choose;
	MSG buf;
	while(1)
	{
		puts("****************************************");
		puts("  1.注册          2.登录          3.退出");
		puts("****************************************");
		scanf("%d",&choose);

		switch(choose)
		{
		case 1:
			deal_register(sockfd,&buf);
			break;
		case 2:
			if(deal_log(sockfd,&buf))//为真 表示登录成功
			{
				deal_dic_history(sockfd,&buf);
			}
			break;
		case 3:
			deal_exit(sockfd,&buf);
			close(sockfd);
			exit(0);

			break;
		default:
			puts("input error");
			break;
		}

		bzero(&buf,sizeof(buf));
		sleep(1);
		system("clear");//清屏
	}
}
//./s ip port
int main(int argc,char*argv[])
{
	if(argc!=3)
	{
		printf("%s 服务器ip 服务器端口\n",argv[0]);
		exit(-1);
	}

	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		perror("socket");
		exit(-1);
	}

	//发起三次握手连接请求
	struct sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(atoi(argv[2]));
	serveraddr.sin_addr.s_addr = inet_addr(argv[1]);
	if(connect(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr))<0)
	{
		perror("bind");
		close(sockfd);
		exit(-1);
	}

	//菜单
	menu(sockfd);

}

#include "apue.h"

int main()
{
	//创建套接字
	int listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if(listenfd < 0)
	{
		perror("socket");
		exit(-1);
	}
	
	//绑定
	struct sockaddr_in self_addr;
	self_addr.sin_family = AF_INET;
	self_addr.sin_port = htons(5678);
	self_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	int ret = bind(listenfd, (struct sockaddr*)&self_addr, sizeof(self_addr));
	if(ret < 0)
	{
		perror("bind");
		close(listenfd);
		exit(-1);
	}
	
	//监听，设置最大连接值
	int ret_listen = listen(listenfd, 5);
	if(ret_listen < 0)
	{
		perror("listen");
		close(listenfd);
		exit(-1);
	}
	
	//阻塞等待连接
	int newconfd = accept(listenfd, NULL, NULL);
	if(newconfd<0)
	{
		perror("accept");
		close(listenfd);
		exit(-1);
	}
	
	//读写数据
	char buf[100] = "\0";
	read(newconfd, buf, sizeof(buf));
	printf("read: %s\n",buf);
	
	//关闭套接字
	close(listenfd);
	close(newconfd);
	
}

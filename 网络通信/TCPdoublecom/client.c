#include "apue.h"

int main()
{
	//创建套接字
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		perror("socket");
		exit(-1);
	}
	
	//发起三次握手连接
	
	//服务器端地址信息
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(5678);
	server_addr.sin_addr.s_addr = inet_addr("192.168.126.136");
	
	int ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if(ret < 0)
	{
		perror("connect");
		close(sockfd);
		exit(-1);
	}
	
	//读写数据
	char buf[100] = "\0";
	scanf("%s",buf);
	write(sockfd, buf, sizeof(buf));
	
	//关闭套接字
	close(sockfd);
	
}

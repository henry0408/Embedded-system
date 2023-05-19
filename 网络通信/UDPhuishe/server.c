#include "apue.h"

int main()
{
	//创建套接字
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockfd < 0)
	{
		perror("socket");
		exit(-1);
	}
	
	//bind绑定
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(5678);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	int ret = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
	if(ret < 0)
	{
		perror("bind");
		close(sockfd);
		exit(-1);
	}
	
	//从client接收
	struct sockaddr_in client_addr;
	socklen_t len = sizeof(struct sockaddr_in);
	ssize_t ret_rcv;	//client的大小
	char buf[100] = "\0";
	
	//发回给client
	ssize_t ret_send;
	
	while(1)
	{
		ret_rcv = recvfrom(sockfd, buf, sizeof(buf),0,(struct sockaddr*)&client_addr, &len);
		if(ret_rcv < 0)
		{
			perror("recvfrom");
			close(sockfd);
			exit(-1);
		}

		printf("recv: %s\n",buf);
		
		ret_send = sendto(sockfd, buf, ret_rcv, 0, (struct sockaddr*)&client_addr, sizeof(client_addr));
		if(ret_send < 0)
		{
			perror("sendto");
			close(sockfd);
			exit(-1);
		}
		
		bzero(buf, sizeof(buf));
	}
	close(sockfd);
}

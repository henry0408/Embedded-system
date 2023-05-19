#include "apue.h"

int main()
{
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		perror("socket");
		exit(-1);
	}
	
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(5678);
	server_addr.sin_addr.s_addr = inet_addr("192.168.126.136");
	
	socklen_t len = sizeof(server_addr);
	int ret =  connect(sockfd, (struct sockaddr *)&server_addr, len);
	if(ret < 0)
	{
		perror("connect");
		close(sockfd);
		exit(-1);
	}

	char buf[100] = "\0";
	int fd = fork();
	if(0 == fd)
	{
		while(1)
		{
			scanf("%s",buf);
			write(sockfd, buf, strlen(buf)+1);
			bzero(buf,sizeof(buf));
		}
	}
	else if(fd > 0)
	{
		while(1)
		{
			read(sockfd, buf, sizeof(buf));
			puts(buf);
			bzero(buf,sizeof(buf));
		}
	}
	else
	{
		perror("fork");
		close(sockfd);
		exit(-1);
	}
}

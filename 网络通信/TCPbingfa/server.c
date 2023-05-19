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
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	int ret = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
	if(ret < 0)
	{
		perror("bind");
		close(sockfd);
		exit(-1);
	}
	
	listen(sockfd, 10);
	
	struct sockaddr_in client_addr;
	socklen_t len = sizeof(client_addr);
	int newconfd = accept(sockfd, (struct sockaddr *)&client_addr, &len);
	if(newconfd < 0)
	{
		perror("accept");
		close(sockfd);
		close(newconfd);
		exit(-1);
	}

	char buf[100] = "\0";
	int fd = fork();
	if(0 == fd)
	{
		while(1)
		{		
			scanf("%s",buf);
			write(newconfd, buf, strlen(buf)+1);
			bzero(buf,sizeof(buf));
		}
	}
	else if(fd > 0)
	{
		while(1)
		{		
			read(newconfd, buf, sizeof(buf));
			puts(buf);
			bzero(buf,sizeof(buf));
		}
	}
	else
	{
		perror("fork");
		close(sockfd);
		close(newconfd);
		exit(-1);
	}
}

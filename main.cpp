#include <stdio.h>          /* printf */
#include <stdlib.h>         /* exit */
#include <string.h>         /* bzero */
#include <sys/socket.h>     /* recv, send */
#include <arpa/inet.h>      /* struct sockaddr */
#include <unistd.h>         /* exit */

/*
Adicionar arquivos:
	git add .
	git commit -m hue
	git push -u origin master

Pegar:
	git pull origin master
*/


#define BUFFSIZE 500
#define MAXPENDING 5

#ifndef _Error
#include "Error.h"
#endif


#define SA struct sockaddr

int main(void)
{
	//ErrorCode error;

	int listenfd, connfd, n;
	unsigned int clientlen;
	char buffer[BUFFSIZE];
	struct sockaddr_in servaddr, client;


	if((listenfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
	{
		Error::printError(createSocket);
		return 0;
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      	= AF_INET;
	servaddr.sin_addr.s_addr 	= htonl(INADDR_ANY);
	servaddr.sin_port        	= htons(8081);

	if(bind(listenfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
	{
		Error::printError(bindSocket);
		return 0;
	}

	if(listen(listenfd, MAXPENDING) < 0)
	{
		Error::printError(listenSocket);
		return 0;
	}

	while(true)
	{
		n = -1;
		clientlen = sizeof(client);

		if((connfd = accept(listenfd, (SA *) &client, &clientlen)) < 0)
		{
			Error::printError(acceptConnection);
			return 0;
		}

		if((n = recv(connfd, buffer, BUFFSIZE, 0)) < 0)
		{
			Error::printError(receiveData);
			return 0;
		}

		printf("%s", buffer);

		close(connfd);
	}
	/*
	Para envio:
	if(send(connfd, buffer, BUFFSIZE, 0) != BUFFSIZE)
	{
		Error::printError(sendData);
	}
	*/

	return 0;
}

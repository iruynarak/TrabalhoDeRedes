
#include <string.h>         /* bzero */
#include <arpa/inet.h>      /* struct sockaddr */
#include <sys/socket.h>     /* recv, send */
#include <unistd.h>         /* exit */


#define BUFFSIZE 500
#define MAXPENDING 5

#ifndef _Error
#include "Error.h"
#endif



int main(void)
{
	//ErrorCode error;

	struct sockaddr_in servaddr, client, connfd, n;
	int listenfd, clientlen;
	char buffer[BUFFSIZE];


	if((listenfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
	{
		Error::printError(createSocket);
		return 0;
	}


	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      	= AF_INET;
	servaddr.sin_addr.s_addr 	= htonl(INADDR_ANY);
	servaddr.sin_port        	= 80;

	if(bind(listenfd, (sockaddr *) &servaddr, sizeof(servaddr)) < 0)
	{
		Error::printError(bindSocket);
		return 0;
	}

	if(listen(listenfd, MAXPENDING) < 0)
	{
		Error::printError(listenSocket);
		return 0;
	}

	clientlen = sizeof(client);

	if((connfd = accept(listenfd, (sockaddr *) &client, &clientlen)) < 0)
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


	/*
	Para envio:
	if(send(connfd, buffer, BUFFSIZE, 0) != BUFFSIZE)
	{
		Error::printError(sendData);
	}
	*/

	return 0;
}

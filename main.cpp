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
/*
 http://127.0.0.1:8081 -> GET /

 http://127.0.0.1:8081/home/karan/Documents/teste.txt -> GET /home/karan/Documents/teste.txt
 * */

/*
Para compilar: g++ -Wall -std=c++11 -o main main.cpp
Para executar: ./main [porta]
*/

#define MAXPENDING 5

#ifndef _Error
#include "Error.h"
#endif

#ifndef _RequestHeader
#include "RequestHeader.h"
#endif

#ifndef _HTTP
#include "HTTP.h"
#endif

#ifndef _ParserHTTP
#include "ParserHTTP.h"
#endif

#define SA struct sockaddr

int main(int argc, char** argv)
{
	//ErrorCode error;

	int listenfd, connfd, n;
	unsigned int clientlen;
	char buffer[BUFFSIZE];
	struct sockaddr_in servaddr, client;

	int receivedDataLength;
	char* receivedDataBuffer = new char[1024000];

	if((listenfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
	{
		Error::printError(createSocket);
		delete [] receivedDataBuffer;
		return 0;
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      	= AF_INET;
	servaddr.sin_addr.s_addr 	= htonl(INADDR_ANY);
	servaddr.sin_port        	= htons(atoi(argv[1]));

	if(bind(listenfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
	{
		Error::printError(bindSocket);
		delete [] receivedDataBuffer;
		return 0;
	}

	if(listen(listenfd, MAXPENDING) < 0)
	{
		Error::printError(listenSocket);
		delete [] receivedDataBuffer;
		return 0;
	}

	while(true)
	{
		n = 0;
		clientlen = sizeof(client);

		if((connfd = accept(listenfd, (SA *) &client, &clientlen)) < 0)
		{
			Error::printError(acceptConnection);
			delete [] receivedDataBuffer;
			return 0;
		}

		receivedDataLength = 0;
		strcpy(receivedDataBuffer,"");

		do
		{
			n = recv(connfd, buffer, BUFFSIZE, 0);

			cout << "\nN " << n << endl;
			cout << "\nSTRLEN " << strlen(buffer) << endl;

			if(n != -1)
			{
				for (int i = 0; i < n; i++)
				{
					receivedDataBuffer[i + receivedDataLength] = buffer[i];
				}
				receivedDataLength += n;
			}
			else
			{
				Error::printError(receiveData);
				delete [] receivedDataBuffer;
				return 0;
			}
		}
		while (n == 1500);

		printf("%s", receivedDataBuffer);

		RequestHeader* requestHeader = ParserHTTP::execute(receivedDataBuffer);
		HTTP* http = new HTTP(requestHeader);
		char* responseText = http->execute(requestHeader);

		/*Map::iterator it;
		cout << '\n';
		for(it = requestHeader->headerFields.begin(); it != requestHeader->headerFields.end(); ++it)
		{
			cout << it->first << "=>" << it->second << '\n';
		}
		cout << '\n';
		*/

		n = 0;
		int i;
		int totalSent = 0;
		char* auxStr = new char[1024000];
		do
		{
			strcpy(auxStr, "");
			for (i = totalSent; i < http->responseLength; i++)
				auxStr[i - totalSent] = responseText[i];

			if ((http->responseLength - totalSent) > BUFFSIZE)
			{
				n = send(connfd, auxStr, BUFFSIZE, 0);
			}
			else
			{
				n = send(connfd, auxStr, (http->responseLength - totalSent), 0);
			}

			if(n != 1)
				totalSent += n;
			else
			{
				Error::printError(sendData);
				delete [] receivedDataBuffer;
				return 0;
			}
		}
		while (totalSent < http->responseLength);

//		delete [] http->responseText;
//		delete [] http->fileData;

		cout << "\nTerminou\n";

		close(connfd);
	}

	delete [] receivedDataBuffer;

	return 0;
}

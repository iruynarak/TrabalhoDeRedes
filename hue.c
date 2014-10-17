#include <stdio.h>          /* printf */
#include <stdlib.h>         /* exit */
#include <string.h>         /* bzero */
#include <sys/socket.h>     /* recv, send */
#include <arpa/inet.h>      /* struct sockaddr */
#include <unistd.h>         /* exit */

#define BUFFSIZE 100
#define MAXPENDING 5
#define SA struct sockaddr


void error(char *msg);

int main(int argc, char *argv[])
{

	//definindo variaveis
	char bufferIP[BUFFSIZE];
	int listenfd, connfd, clientlen, n;
	char buffer[BUFFSIZE];
	struct sockaddr_in servaddr, client;

	//leitura de dados
	if(argc != 2)
		error("Use: SERVERecho <porta>");

	if((listenfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		error("Falha ao criar o socket");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(atoi(argv[1]));

	if(bind(listenfd, (SA *) &servaddr, sizeof(servaddr)) < 0)
	{
		error("Falha ao observar o socket do servidor");
		return 0;
	}


	if(listen(listenfd, MAXPENDING) < 0)
		error("Falha ao tentar escutar o socket do servidor");

	for( ; ; )
	{
		n = -1;
		clientlen = sizeof(client);

		if((connfd = accept(listenfd, (SA *) &client, &clientlen)) < 0)
			error("Falhou ao aceitar a conexao do cliente");


		while(1)
		{
			printf("Client[%s]: ", inet_ntoa(client.sin_addr));


			if((n = recv(connfd, buffer, BUFFSIZE, 0)) < 0)
				error("Falhou ao receber os dados restantes do cliente");

			//buffer[n] = '\0';
			printf("%s", buffer);

			printf("\nYou: ");

			scanf("%s", buffer);


			if(send(connfd, buffer, BUFFSIZE, 0) != BUFFSIZE)
				error("Falhou ao enviar os dados devolta para o cliente");

		}





		close(connfd);
	}
	return 0;
}

/* Imprime mensagens de erro */
void error(char *msg)
{
	printf("%s\n", msg);

	return;
}

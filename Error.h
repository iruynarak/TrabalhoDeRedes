#ifndef _Error
#define _Error
#endif

#include<stdio.h>

typedef enum ErrorCode
{
	createSocket,
	bindSocket,
	listenSocket,
	acceptConnection,
	receiveData,
	sendData,
	badRequest,
	notFound,
	versionNotSupported,
	openFile,
	openDir
} ErrorCode;

class Error
{
	public:
		static void printError(ErrorCode error)
		{
			switch (error)
			{
				case createSocket:
					printf("Error: Falha ao criar o socket\n");
				case bindSocket:
					printf("Error: Falha ao observar o socket do servidor\n");
				case listenSocket:
					printf("Error: Falha ao tentar escutar o socket do servidor\n");
				case acceptConnection:
					printf("Error: Falhou ao aceitar a conexao do cliente\n");
				case receiveData:
					printf("Error: Falhou ao receber os dados restantes do cliente\n");
				case sendData:
					printf("Error:Falhou ao enviar os dados devolta para o cliente\n");
				case badRequest:
					printf("Error:Bad Request\n");
				case notFound:
					printf("Error:Not Found\n");
				case versionNotSupported:
					printf("Error:Version Not Supported\n");
				case openFile:
					printf("Error: Não foi possível abrir o arquivo\n");
				case openDir:
					printf("Error: Não foi possível abrir o diretório\n");


			}

		}
};

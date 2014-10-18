#ifndef _ParserHTTP
#define _ParserHTTP
#endif

#ifndef _RequestHeader
#include "RequestHeader.h"
#endif

#include <string>

using namespace std;
/**
 * \class ParserHTTP
 * Classe responsável pela interpretação do cabeçalho do HTTP Request
 */
class ParserHTTP
{
	public:

		/*

		 O formato pode ser encontrado em:
			http://www.w3.org/Protocols/rfc2616/rfc2616-sec5.html
			http://www.w3.org/Protocols/rfc2616/rfc2616.html
		*/


		/**
		 * Método que realiza a interpretação do cabeçalho do HTTP Request
		 * \param header Texto contendo o cabeçalho do HTTP Request
		 */
		static RequestHeader* execute(string header)
		{
			RequestHeader* requestHeader;
			/*
			Primeira linha:

				Request-Line = Method SP Request-URI SP HTTP-Version CRLF

				Method = POST | GET (Apenas para o trabalho. Outros métodos existem, mas não serão úteis para o trabalho)

				SP = espaço

				CRLF = quebra de linha = \r\n

				Request-URI = Request-URI    = "*" | absoluteURI | abs_path | authority

				HTTP-Version = No nosso caso HTTP/1.1

			*/

			int i = 0;


			string postRequest = "POST";

			string badRequest = "Bad Request";

			string HTTPVersion = "HTTP/1.1";

			string word;

			string method;

			string requestURI;

			while(true)
			{
				/*
				 * Method
				 */
				while(header[i] != ' ')
				{
					word += header[i];
					i++;
				}
				i++;

				if (word == "GET" || word == "POST")
					method = word;
				else
					method = badRequest;

				word = "";

				/*
				 * Request URI
				 */
				while(header[i] != ' ')
				{
					word += header[i];
					i++;
				}
				i++;

				requestURI = word;

				word = "";

				requestHeader = new RequestHeader(method, requestURI);

				/*
				 * HTTP Version
				 */
				while(header[i] != '\r')
				{
					word += header[i];
					i++;
				}
				i++;

				if(header[i] == '\0')
				{
					break;
				}

			}



			return requestHeader;
		}
};

#ifndef _ParserHTTP
#define _ParserHTTP
#endif

#ifndef _RequestHeader
#include "RequestHeader.h"
#endif

#include <string>
#include <iostream>

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

			string word = "";

			string key = "";

			string value = "";

			string method;

			string requestURI;

			bool notData = true;

			for ( ; header[i] != ' '; i++)
				word += header[i];
			i = ParserHTTP::skipTillLetter(i, header);

			if (word == "GET" || word == "POST")
				method = word;

			word = "";
			for ( ; header[i] != ' '; i++)
				word += header[i];
			i = ParserHTTP::skipTillLetter(i, header);

			requestURI = word;

			requestHeader = new RequestHeader(method, requestURI);

			word = "";
			for ( ; header[i] != '\r'; i++)
				word += header[i];

			requestHeader->HTTPVersion = word;

			while (notData)
			{
				i = ParserHTTP::skipTillLetter(i, header);

				word = "";
				for ( ; header[i] != ':'; i++)
					word += header[i];
				i = ParserHTTP::skipTillLetter(i, header);

				key = word;

				word = "";
				for ( ; header[i] != '\r'; i++)
					word += header[i];
				notData = !ParserHTTP::verifyHeaderFieldsEnd(i, header);

				value = word;

				requestHeader->insert(key,value);
			}

			word = "";
			for ( ; header[i] != '\0'; i++)
				word += header[i];

			requestHeader->messageBody = word;

			return requestHeader;
		}

		static int skipTillLetter(int i, string header)
		{
			while (header[i] == ' ' || header[i] == ':' || header[i] == '\r' || header[i] == '\n')
				i++;
			return i;
		}

		static bool verifyHeaderFieldsEnd(int i, string header)
		{
			bool result = false;

			if (header[i] == '\r')
			{
				i++;
				if (header[i] == '\n')
				{
					i++;
					if (header[i] == '\r')
					{
						i++;
						if (header[i] == '\n')
						{
							i++;
							result = true;
						}
					}
					else
						result = false;
				}
				else
					result = false;
			}
			else
				result = false;

			return result;
		}
};

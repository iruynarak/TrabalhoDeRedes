#ifndef _HTTP
#define _HTTP
#endif

#ifndef _Error
#include "Error.h"
#endif

#ifndef _RequestHeader
#include "RequestHeader.h"
#endif

#include <string>
#include <string.h>
#include <fstream>
#include <sys/stat.h>
#include <iostream>

#define BUFFSIZE 700

using namespace std;

class HTTP
{
	public:
		RequestHeader* requestHeader;

		HTTP(RequestHeader* requestHeader)
		{
			this->requestHeader = requestHeader;
		}

		char* execute(RequestHeader* requestHeader)
		{

			//char* responseText = new char[BUFFSIZE];

			//strcpy(responseText, "HTTP/1.1 404 Not Found\r\nContent-type: text/html\r\n\r\n Not Found O_O");

			//return responseText;

			if(requestHeader->HTTPVersion == "HTTP/1.1")
			{

				if(requestHeader->method == "GET")
				{
					return this->doGet();
				}
				else if(requestHeader->method == "POST")
				{
					return this->doPost();
				}
				else
				{
					Error::printError(badRequest);
					return this->doBadRequest();
				}
			}
			else
			{
				Error::printError(versionNotSupported);
				return doVersionNotSupported();
			}

			Error::printError(badRequest);
			return doBadRequest();
		}

		char* doBadRequest();

		char* doVersionNotSupported();

		char* doNotFound();

		char* doGet();

		char* doPost();

		string getData();

		bool isDirectory(const char* path);

		bool isFile(const char* path);

		char* doGetDirectory();

		char* doGetFile();

};

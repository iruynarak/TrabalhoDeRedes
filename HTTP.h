#ifndef _HTTP
#define _HTTP
#endif

#ifndef _Error
#include "Error.h"
#endif

#ifndef _RequestHeader
#include "RequestHeader.h"
#endif

#ifndef _GetExtension
#include "GetExtension.h"
#endif

#ifndef _DirectoryManager
#include "DirectoryManager.h"
#endif

#include <string>
#include <string.h>
#include <fstream>
#include <sys/stat.h>
#include <iostream>
#include <stdlib.h>

#define BUFFSIZE 1500

using namespace std;

class HTTP
{
	public:
		RequestHeader* requestHeader;

		int responseLength;

		char* responseText;

		char* fileData;

		HTTP(RequestHeader* requestHeader)
		{
			this->requestHeader = requestHeader;
		}

		char* execute(RequestHeader* requestHeader)
		{

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

		char* getData(int* dataLength);

		bool isDirectory(const char* path);

		bool isFile(const char* path);

		char* doGetDirectory();

		char* doGetFile();

};

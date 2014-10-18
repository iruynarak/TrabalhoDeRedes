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
#define BUFFSIZE 700


class HTTP
{
	public:
		RequestHeader* requestHeader;

		HTTP(RequestHeader* requestHeader)
		{
			this->requestHeader = requestHeader;
		}

		static char* execute(RequestHeader* requestHeader)
		{

			char* responseText = new char[BUFFSIZE];

			strcpy(responseText, "HTTP/1.1 404 Not Found\r\nContent-type: text/html\r\n\r\n Not Found O_O");

			return responseText;

//			if(requestHeader->HTTPVersion == "HTTP/1.1")
//			{
//
//				if(requestHeader == "GET")
//				{
//					return doGet();
//				}
//				else if(requestHeader == "POST")
//				{
//					return doPost();
//				}
//				else
//				{
//					Error::printError(badRequest);
//					return doBadRequest();
//				}
//			}
//			else
//			{
//				Error::printError(VersionNotSupported);
//				return doVersionNotSupported();
//			}
//
//			Error::printError(badRequest);
//			return doBadRequest();
		}

		char* doBadRequest();

		char* doVersionNotSupported();

		char* doNotFound();

		char* doGet();

		char* doPost();

		char* getData();

};

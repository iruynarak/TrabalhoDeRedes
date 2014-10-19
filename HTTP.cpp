#ifndef _HTTP
#include "HTTP.h"
#endif


char* HTTP::doBadRequest()
{
	char* responseText = new char[BUFFSIZE];
	strcpy(responseText, "HTTP/1.1 400 Bad Request\r\nContent-type: text/html\r\n\r\nBad Requestd");
	return responseText;
}

char* HTTP::doVersionNotSupported()
{
	char* responseText = new char[BUFFSIZE];
	strcpy(responseText, "HTTP/1.1 505 HTTP Version Not Supported\r\nContent-type: text/html\r\n\r\nVersion Not Supported");
	return responseText;
}

char* HTTP::doNotFound()
{
	char* responseText = new char[BUFFSIZE];
	strcpy(responseText, "HTTP/1.1 404 Not Found\r\nContent-type: text/html\r\n\r\nNot found");

	return responseText;
}

char* HTTP::doGet()
{
	char* responseText = new char[BUFFSIZE];

	responseText = getData();

	if(isFile(requestHeader->requestURI.c_str()))
	{
		return doGetFile();
	}
	else if(isDirectory(requestHeader->requestURI.c_str()))
	{
		return doGetDirectory();
	}

	else
	{
		return doBadRequest();
	}


	return responseText;
}

//todo:
char* HTTP::doPost()
{
	char* responseText = new char[BUFFSIZE];

	return responseText;
}

//todo:
char* HTTP::getData()
{
	char* responseText = new char[BUFFSIZE];


	ifstream file(requestHeader->requestURI);

	return responseText;
}

bool HTTP::isFile(const char* path) {
    struct stat buf;
    stat(path, &buf);
    return S_ISREG(buf.st_mode);
}

bool HTTP::isDirectory(const char* path) {
    struct stat buf;
    stat(path, &buf);
    return S_ISDIR(buf.st_mode);
}

//todo:
char* HTTP::doGetFile()
{
	char* responseText = new char[BUFFSIZE];


	ifstream file(requestHeader->requestURI);

	return responseText;
}

//todo:
char* HTTP::doGetDirectory()
{
	char* responseText = new char[BUFFSIZE];


	ifstream file(requestHeader->requestURI);

	return responseText;
}

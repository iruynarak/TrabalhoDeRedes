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
	strcpy(responseText, "HTTP/1.1 404 Not Found\r\nContent-type: text/html\r\n\r\nNOT FOUND");

	return responseText;
}

char* HTTP::doGet()
{
	char* responseText = new char[BUFFSIZE];



	return responseText;
}

char* HTTP::doPost()
{
	char* responseText = new char[BUFFSIZE];



	return responseText;
}



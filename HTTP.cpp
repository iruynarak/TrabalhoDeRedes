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
	cout << "Entrei na doGet\n";
	if(isFile(requestHeader->requestURI.c_str()))
	{

		return doGetFile();
	}
	else if(isDirectory(requestHeader->requestURI.c_str()))
	{
		return doGetDirectory();
	}

	return doBadRequest();
}

//todo:
char* HTTP::doPost()
{
	cout << "Entrei na doPost\n";
	char* responseText = new char[BUFFSIZE];

	return responseText;
}

//todo:
string HTTP::getData()
{
	cout << "Entrei aqui na getData\n";
	string line;
	string total;
	ifstream file(requestHeader->requestURI.c_str());
	if(file.is_open())
	{
		while(getline(file,line))
		{
			total += line;
			cout << line << '\n';
		}

		file.close();
	}
	else
	{
		Error::printError(openFile);
	}
	return total;
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
	cout << "Entrei na doGetFile()\n";
	char* responseText = new char[BUFFSIZE];

	string data = getData();

	cout<< "\n\nlength:" << data.length() << "\n\n";
	char* length = new char[15];
	sprintf(length,"%d", data.length());
	string crlf = "\r\n";
	string type = GetExtension::getExtension(requestHeader->requestURI);
	string contentType = GetExtension::getMIME(type);
	string responseTextString =
			"HTTP/1.1 200 OK"
			+ crlf
			+ "Content-Type: "
			+ contentType;
			+ crlf
			+ "Content-Length: "
			+ contentType
			+ crlf
			+ length
			+ crlf
			+ crlf
			+ data;
	int i;
	for(i = 0; i < responseTextString.length(); i++)
	{
		responseText[i] = responseTextString[i];
	}
	cout << responseTextString << '\n';

	responseText[i] = '\0';
	return responseText;
}

//todo:
char* HTTP::doGetDirectory()
{
	char* responseText = new char[BUFFSIZE];
	cout << "entrei na doGetDirectory\n";
	ifstream file(requestHeader->requestURI.c_str());

	return responseText;
}

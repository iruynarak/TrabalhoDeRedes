#ifndef _HTTP
#include "HTTP.h"
#endif



char* HTTP::doBadRequest()
{
	responseText = new char[BUFFSIZE];
	strcpy(responseText, "HTTP/1.1 400 Bad Request\r\nContent-type: text/html\r\n\r\nBad Requestd");
	return responseText;
}

char* HTTP::doVersionNotSupported()
{
	responseText = new char[BUFFSIZE];
	strcpy(responseText, "HTTP/1.1 505 HTTP Version Not Supported\r\nContent-type: text/html\r\n\r\nVersion Not Supported");
	return responseText;
}

char* HTTP::doNotFound()
{
	responseText = new char[BUFFSIZE];
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
char* HTTP::getData(int* dataLength)
{
	cout << "Entrei aqui na getData\n";
	fileData = new char[99999999];
	char c;

//	if (GetExtension::getExtension(requestHeader->requestURI.c_str()) == "png" ||
//			GetExtension::getExtension(requestHeader->requestURI.c_str()) == "jpg")
//	{
		ifstream file(requestHeader->requestURI.c_str(), ios::binary | ios::in);

		file.seekg (0, file.end);
		*dataLength = file.tellg();
		file.seekg (0, file.beg);

		if (file.is_open())
		{
			for (int i = 0; i < *dataLength; i++)
			{
				file.get(c);

				fileData[i] = c;
			}

			file.close();
		}
//	}
//	else// if (GetExtension::getExtension(requestHeader->requestURI.c_str()) == "html")
//	{
//		ifstream file(requestHeader->requestURI.c_str());
//
//		file.seekg (0, file.end);
//		*dataLength = file.tellg();
//		file.seekg (0, file.beg);
//
//		if (file.is_open())
//		{
//			for (int i = 0; i < *dataLength; i++)
//			{
//				file.get(c);
//
//				fileData[i] = c;
//			}
//
//			file.close();
//		}
//	}
//	else
//	{
//		Error::printError(openFile);
//	}

	return fileData;
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
	cout << "Entrei na doGetFile\n";
	responseText = new char[99999999];
	cout << "Chegou\n";
	int dataLength;

	char* data = getData(&dataLength);

	char* crlf = new char[sizeof("\r\n")];

	strcpy(crlf, "\r\n");

	char* type = new char[GetExtension::getExtension(requestHeader->requestURI).size()];

	strcpy(type, GetExtension::getExtension(requestHeader->requestURI).c_str());

	char* contentType = new char[GetExtension::getMIME(type).size()];

	strcpy(contentType, GetExtension::getMIME(type).c_str());

	strcpy(responseText, "HTTP/1.1 200 OK");

	strcat(responseText, crlf);

	strcat(responseText, "Content-Type: ");

	strcat(responseText, contentType);

	strcat(responseText, crlf);

	strcat(responseText, "Content-Length: ");

	char* charDataLength = new char[sizeof("%d")];

	sprintf(charDataLength, "%d", dataLength);

	strcat(responseText, charDataLength);

	strcat(responseText, crlf);

	strcat(responseText, crlf);

	cout << "Chegou2\n";

	int strLength = strlen(responseText);

	for (int i = 0; i < dataLength; i++)
	{
		responseText[i + strLength] = data[i];
	}
	cout << "Chegou3\n";
	responseLength = strLength + dataLength;

	delete [] crlf;
	delete [] type;
	delete [] contentType;
	delete [] charDataLength;

	return responseText;
}

//todo:
char* HTTP::doGetDirectory()
{
	char* responseText = new char[BUFFSIZE];
	cout << "entrei na doGetDirectory\n";

	DirectoryManager directoryManager;
	directoryManager.openDirectory(requestHeader->requestURI);
	directoryManager.printDirectory();
	directoryManager.closeDirectory();

	ifstream file(requestHeader->requestURI.c_str());

	return responseText;
}

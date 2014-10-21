#ifndef _GetExtension
#define _GetExtension
#endif

#include <string>
#include <iostream>

using namespace std;
class GetExtension
{
	public:
		static string getExtension(string path)
		{

			size_t pos = path.find(".");
			string extension = path.substr(pos+1);
			return extension;
		}

		static string getMIME(string type)
		{
			string contentType;
			if(type == "7z")
			{
				contentType = "application/x-7z-compressed";
			}
			else if (type == "pdf")
			{
				contentType = "application/pdf";
			}
			else if (type == "xml")
			{
				contentType = "application/atom+xml";
			}
			else if(type == "avi")
			{
				contentType = "video/x-msvideo";
			}
			else if(type == "bin")
			{
				contentType = "application/octet-stream";
			}
			else if(type == "torrent")
			{
				contentType = "application/x-bittorrent";
			}
			else if(type == "sh")
			{
				contentType = "application/x-sh";
			}
			else if(type == "c")
			{
				contentType = "text/x-c";
			}
			else if(type == "css")
			{
				contentType = "text/css";
			}
			else if(type == "csv")
			{
				contentType = "text/csv";
			}
			else if(type == "deb")
			{
				contentType = "application/x-debian-package";
			}
			else if(type == "dvi")
			{
				contentType = "application/x-dvi";

			}
			else if(type == "gif")
			{
				contentType = "image/gif";
			}
			else if(type == "jar")
			{
				contentType = "application/java-archive";
			}
			else if(type == "java")
			{
				contentType = "text/x-java-source,java";
			}
			else if(type == "js")
			{
				contentType = "application/javascript";
			}
			else if(type == "jpg")
			{
				contentType = "image/jpeg";
			}
			else if(type == "jpeg")
			{
				contentType = "image/jpeg";
			}
			else if(type == "exe")
			{
				contentType = "application/x-msdownload";
			}
			else if(type == "ppt")
			{
				contentType = "application/vnd.ms-powerpoint";
			}
			else if(type == "wma")
			{
				contentType = "audio/x-ms-wma";
			}

			else if(type == "doc")
			{
				contentType = "application/msword";
			}
			else if(type == "xps")
			{
				contentType = "application/vnd.ms-xpsdocument";
			}
			else if(type == "mp4")
			{
				contentType = "video/mp4";
			}
			else if(type == "png")
			{
				contentType = "image/png";
			}

			else if(type == "rmp")
			{
				contentType = "audio/x-pn-realaudio-plugin";
			}
			else if(type == "svg")
			{
				contentType = "image/svg+xml";
			}
			else if(type == "xhtml")
			{
				contentType = "application/xhtml+xml";
			}
			else if(type == "xml")
			{
				contentType = "application/xml";
			}
			else if(type == "zip")
			{
				contentType = "application/zip";
			}
			else if(type == "gif")
			{
				contentType = "image/gif";
			}
			else if(type == "html")
			{
				contentType = "text/html";
			}
			else if (type == "tex")
			{
				contentType = "application/x-tex";
			}
			else
			{
				contentType = "text/html";
			}
			return contentType;
		}
};


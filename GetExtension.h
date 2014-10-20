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
			cout << extension << '\n';
			return extension;
		}

		static string getMIME(string type)
		{
			string contentType;
			switch(type)
			{
				case "7z":
					contentType = "application/x-7z-compressed";
					break;

				case "pdf":
					contentType = "application/pdf";
					break;

				case ".xml":
					contentType = "application/atom+xml";
					break;

				case "avi":
					contentType = "video/x-msvideo";
					break;

				case "bin":
					contentType = "application/octet-stream";
					break;

				case "torrent":
					contentType = "application/x-bittorrent";
					break;

				case "sh":
					contentType = "application/x-sh";
					break;

				case "c":
					contentType = "text/x-c";
					break;

				case "css":
					contentType = "text/css";
					break;

				case "csv":
					contentType = "text/csv";
					break;

				case "deb":
					contentType = "application/x-debian-package";
					break;

				case "dvi":
					contentType = "application/x-dvi";
					break;

				case "gif":
					contentType = "image/gif";
					break;

				case "jar":
					contentType = "application/java-archive";
					break;

				case "java":
					contentType = "text/x-java-source,java";
					break;

				case "js":
					contentType = "application/javascript";
					break;

				case "jpg":
					contentType = "image/jpeg";
					break;

				case "jpeg":
					contentType = "image/jpeg";
					break;

				case "exe":
					contentType = "application/x-msdownload";
					break;

				case "ppt":
					contentType = "application/vnd.ms-powerpoint";
					break;

				case "wma":
					contentType = "audio/x-ms-wma";
					break;

				case "doc":
					contentType = "application/msword";
					break;

				case "xps":
					contentType = "application/vnd.ms-xpsdocument";
					break;

				case "mp4":
					contentType = "video/mp4";
					break;

				case "png":
					contentType = "image/png";
					break;

				case "rmp":
					contentType = "audio/x-pn-realaudio-plugin";
					break;

				case "svg":
					contentType = "image/svg+xml";
					break;

				case "xhtml":
					contentType = "application/xhtml+xml";
					break;

				case "xml":
					contentType = "application/xml";
					break;

				case "zip":
					contentType = "application/zip";
					break;

			}
			return contentType;
		}
};


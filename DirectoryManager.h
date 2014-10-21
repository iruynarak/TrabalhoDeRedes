//http://www.dreamincode.net/forums/topic/59943-accessing-directories-in-cc-part-i/

#ifndef _DirectoryManager
#define _DirectoryManager
#endif

#include <dirent.h>
#include <string>

using namespace std;
class DirectoryManager
{
	private:
		//ponteiro para um diretorio
		DIR* directoryPointer;
		struct dirent *directoryInfo;
		string directory;
	public:
		DirectoryManager()
		{
			directoryInfo = 0;
			directoryPointer = 0;
		}

		bool openDirectory(string directory)
		{
			this->directory = directory;
			directoryPointer = opendir(directory.c_str());
			if(directoryPointer == 0)
			{
				Error::printError(openDir);
				return false;
			}
			return true;
		}

		void printDirectory()
		{
			while((directoryInfo = readdir(directoryPointer)))
			{
				cout << directoryInfo->d_name << '\n';
			}

		}

		string createHTML()
		{

			string html = "<!DOCTYPE html>\n<body>\n<h1>Index of</h1>\n";


			while((directoryInfo = readdir(directoryPointer)))
			{

				cout <<directoryInfo->d_name;
				html+= "<li>";
				html+="<a href=http:/";
				html+= directory;
				html+= directoryInfo->d_name;
				html+=">";
				html+=directoryInfo->d_name;
				html+="</a>";
				html+="\n";

			}
			html += "<\\ul>\n</body>\n</html>\n";
			return html;
		}

		void closeDirectory()
		{
			closedir(directoryPointer);
		}



};

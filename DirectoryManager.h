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
	public:
		DirectoryManager()
		{
			directoryInfo = 0;
			directoryPointer = 0;
		}

		bool openDirectory(string directory)
		{
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

		void closeDirectory()
		{
			closedir(directoryPointer);
		}

};

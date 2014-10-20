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
};


#include "Directory.h"

using std::string;

Directory::Directory(string _dirName)
{
	dirName = _dirName;

	DIR *dir;
	dirent *ent;
	if ((dir = opendir(dirName.c_str())) != NULL) 
	{
		while ((ent = readdir(dir)) != NULL) 
		{
			if (ent->d_type == DT_REG)
			{
				string fileString(ent->d_name);
				fileNames.push_back(fileString);
			}
			if (ent->d_type == DT_DIR)
			{
				string dirString(ent->d_name);
				dirNames.push_back(dirString);
			}
		}
		closedir(dir);
	}
	else {
		perror("");
	}
}

Directory::~Directory()
{
}

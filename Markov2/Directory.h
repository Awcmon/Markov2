#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "dirent.h"

class Directory
{
public:
	std::string dirName;

	std::vector<std::string> fileNames;
	std::vector<std::string> dirNames;

	Directory(std::string dirName);
	~Directory();
};


#include <iostream>
#include <fstream>
#include <regex>
#include "markov.h"
#include "Directory.h"

using std::vector;
using std::string;
using std::map;
using std::cout;

vector<string> explode(string const & s, char delim)
{
	vector<std::string> result;
	std::istringstream iss(s);
	for (string token; std::getline(iss, token, delim); )
	{
		result.push_back(move(token));
	}
	return result;
}

template<typename T, typename A>
void printVec(std::vector<T, A> const& vec, string delim) 
{
	for (int i = 0; i < (int)vec.size(); i++)
	{
		std::cout << vec[i] << delim;
	}
}

bool strMatch(string str, string regex)
{
	std::regex e(regex);
	std::smatch sm;
	return std::regex_match(str, sm, e);
}

void writeFile(string file, string content)
{
	std::ofstream ofs;
	ofs.open(file, std::ofstream::out | std::ofstream::trunc);

	ofs << content;

	ofs.close();
}

int main()
{
	string directoryname = "samples";
	Directory dir(directoryname);

	string total = "";
	for (int i = 0; i < (int)dir.fileNames.size(); i++)
	{
		string curFile = dir.fileNames[i];
		if (strMatch(curFile, ".*(\\.txt)"))
		{
			cout << curFile << "\n";
			std::ifstream ifs(directoryname+"/"+curFile);
			std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
			total = total + content;
		}
	}

	cout << "-----\n";

	int numWords = 300;
	int prefixLen = 2;

	Chain c(prefixLen);

	vector<string> sample = explode(total, ' ');
	cout << sample.size() << " words.\n";
	c.build(sample);

	string output = c.generate(numWords);
	cout << output;
	writeFile("output.txt", output);

	cout << "\n";

	return 0;
}

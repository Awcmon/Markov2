
#pragma once

#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <random>
#include <algorithm>


class Prefix
{
public:
	std::vector<std::string> p;

	Prefix();

	std::string toString();
	void shift(std::string word);
};

class Chain
{
public:
	std::map<std::string, std::vector<std::string>> chain;
	int prefixLen;

	Chain(int _prefixLen);

	void build(std::vector<std::string> input);
	std::string generate(int n);
};

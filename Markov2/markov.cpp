
#include "markov.h"

using std::vector;
using std::string;
using std::map;

string concatStrVec(vector<string> v)
{
	string ret = "";
	for (int i = 0; i < (int)v.size(); i++)
	{
		ret = ret + v[i] + " ";
	}
	return ret;
}

Prefix::Prefix()
{
}

string Prefix::toString()
{
	string ret = "";
	for (int i = 0; i < (int)p.size(); i++)
	{
		ret = ret + p[i];
	}
	return ret;
}

void Prefix::shift(string word)
{
	if (p.size() > 1)
	{
		p.erase(p.begin());
	}
	p.push_back(word);
}

Chain::Chain(int _prefixLen)
{
	prefixLen = _prefixLen;
}

void Chain::build(vector<string> input)
{
	Prefix p;
	for (int i = 0; i < (int)input.size(); i++)
	{
		string s = input[i];
		string key = p.toString();
		//chain[key];
		chain[key].push_back(s);
		p.shift(s);
	}
}

string Chain::generate(int n)
{
	Prefix p;
	vector<string> words;
	for (int i = 0; i < n; i++)
	{
		vector<string> choices = chain[p.toString()];
		if (choices.size() == 0)
		{
			break;
		}
		std::random_device rd;
		std::minstd_rand g(rd());
		auto rand = std::uniform_int_distribution<int>{ 0, (int)(choices.size() - 1) }(g);
		string next = choices[rand];
		words.push_back(next);
		p.shift(next);
	}
	return concatStrVec(words);
}

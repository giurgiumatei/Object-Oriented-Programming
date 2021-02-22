#pragma once
#include <vector>
#include <string>
#include <sstream>
using namespace std;


class Utilities
{
public:
	Utilities()
	{

	}
	string strip(std::string arg)
	{
		int end_of_string = arg.size() - 1, i = 0;
		while (arg[i] == ' ')
			i++;
		while (arg[end_of_string] == ' ')
			end_of_string--;
		return arg.substr(i, end_of_string - i);
	}


	static vector<string> split_parameters(string line, char delimiter)
	{
		vector<string> result;
		string argument;
		stringstream stream(line);

		while (getline(stream, argument, delimiter))
		{
			//argument = strip(argument);

			result.push_back(argument);
		}

		return result;
	}
};
#include "Domain.h"

Entity::Entity(string first_string, string second_string, int first_int, int second_int)
{
	this->first_string = first_string;
	this->second_string = second_string;
	this->first_int = first_int;
	this->second_int = second_int;
}

string Entity::get_first_string()
{
	return this->first_string;
}

string Entity::get_second_string()
{
	return this->second_string;
}

int Entity::get_second_int()
{
	return this->second_int;
}

int Entity::get_first_int()
{
	return this->first_int;
}

istream& operator>>(istream& input, Entity& entity)
{
	string line;
	getline(input, line);

	if (line.size() == 0)
	{
		return input;
	}

	int position = line.find(" | ");
	string first_string = line.substr(0, position);
	line.erase(0, position + 3);
	 position = line.find(" | ");
	string second_string = line.substr(0,position);
	line.erase(0, position + 3);
	 position = line.find(" | ");
	string first_int_string= line.substr(0, position);
	int first_int = stoi(first_int_string);
	line.erase(0, position + 3);
	string second_int_string = line;
	int second_int = stoi(second_int_string);

	entity = Entity(first_string, second_string, first_int, second_int);

	return input;



}

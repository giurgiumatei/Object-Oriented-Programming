#include "Domain.h"
Vegetable::Vegetable(string family, string name, string parts)
{

	this->family = family;
	this->name= name;
	this->parts = parts;
}

string Vegetable::get_family()
{
	return this->family;
}

string Vegetable::get_name()
{
	return this->name;
}

string Vegetable::get_parts()
{
	return this->parts;
}


istream& operator>>(istream& input, Vegetable& vegetable)
{
	string line;
	getline(input, line);

	if (line.size() == 0)
	{
		return input;
	}

	int position = line.find(" | ");
	string family = line.substr(0, position);
	line.erase(0, position + 3);
	position = line.find(" | ");
	string name = line.substr(0, position);
	line.erase(0, position + 3);
	string parts = line;
	

	vegetable = Vegetable(family, name, parts);

	return input;
}

ostream& operator<<(ostream& output, Vegetable& vegetable)
{
	output << vegetable.get_family() << " | " << vegetable.get_name() << " | " << vegetable.get_parts() << "\n";
	return output;
}

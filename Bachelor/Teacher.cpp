#include "Teacher.h"

string Teacher::get_name()
{
    return name;
}


istream& operator>>(istream& input, Teacher& teacher)
{
	string line;
	getline(input, line);

	if (line.size() == 0)
	{
		return input;
	}

	
	string name = line;



	teacher = Teacher(name);

	return input;
}
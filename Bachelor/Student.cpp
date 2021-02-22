#include "Student.h"

string Student::get_id() 
{
    return this->id;
}



string Student::get_name()
{
    return this->name;
}



string Student::get_email()
{
    return this->email;
}

void Student::set_email(string email)
{
    this->email = email;
}

int Student::get_year() 
{
    return year;
}

string Student::get_title() 
{
    return this->title;
}

void Student::set_title(string title)
{
    this->title = title;
}

string Student::get_coordinator() 
{
    return this->coordinator;
}

void Student::set_coordinator(string coordinator)
{
    this->coordinator = coordinator;
}

istream& operator>>(istream& input, Student& student)
{
	string line;
	getline(input, line);

	if (line.size() == 0)
	{
		return input;
	}

	int position = line.find(" | ");
	string id = line.substr(0, position);
	line.erase(0, position + 3);
	position = line.find(" | ");
	string name = line.substr(0, position);
	line.erase(0, position + 3);
	position = line.find(" | ");
	string email = line.substr(0, position);
	line.erase(0, position + 3);
	position = line.find(" | ");
	string year_string = line.substr(0, position);
	int year = stoi(year_string);
	line.erase(0, position + 3);
	position = line.find(" | ");
	string title = line.substr(0, position);
	line.erase(0, position + 3);
	string coordinator = line;

	

	student = Student(id,name,email,year,title,coordinator);

	return input;
}
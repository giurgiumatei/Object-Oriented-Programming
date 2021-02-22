#pragma once
#include "Utilities.h"
#include <iostream>
#include <fstream>


class User
{

private:
	string name;
	string type;
public:
	User()
	{

	}
	User(string name, string type) :name{ name }, type{ type }{}


    string getName() const;
    void setName(string name);

    string getType() const;
    void setType(string type);

	friend ifstream& operator>> (ifstream& input, User& user);
	//friend ofstream& operator<< (ofstream& output, User& user);

};


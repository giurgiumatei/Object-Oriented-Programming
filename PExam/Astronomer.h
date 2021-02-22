#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "Utilities.h"
using namespace std;


class Astronomer
{

private:

	string name;
	string constelation;
public:
	Astronomer()
	{

	}

	Astronomer(string name, string constelation) :name{ name }, constelation{ constelation }{}
    string getName() const;
    void setName(string name);

    string getConstelation() const;
    void setConstelation(string constelation);
	friend ifstream& operator>> (ifstream& input, Astronomer& astronomer);

};


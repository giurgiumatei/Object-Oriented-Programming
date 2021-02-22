
#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "Utilities.h"
using namespace std;


class Screenwriter
{
private:
	string name;
	string expertize;
public:

	Screenwriter()
	{

	}
	Screenwriter(string name, string expertize):name { name }, expertize{ expertize }{}


public:
    string getName() const;
    void setName(string name);

    string getExpertize() const;
    void setExpertize(string expertize);
	friend ifstream& operator>> (ifstream& input, Screenwriter& screenwriter);
	

};


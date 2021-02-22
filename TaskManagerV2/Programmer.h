#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "Utilities.h"
using namespace std;
class Programmer
{
private:
	string name;
	int id;



public:
    string getName() const;
    void setName(string name);

    int getId() const;
    void setId(int id);

    friend ifstream& operator>> (ifstream& input, Programmer& programmer);
};


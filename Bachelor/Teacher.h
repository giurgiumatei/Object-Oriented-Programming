#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Teacher
{
private:
	string name;



public:
	Teacher()
	{

	};
	Teacher(string name) :name{ name } {}
    string get_name() ;
    friend istream& operator>>(istream& input, Teacher& teacher);

};


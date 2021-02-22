#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Entity
{

private:

	string first_string;
	string second_string;
	int first_int;
	int second_int;
public:
	Entity()
	{

	};

	Entity(string first_string, string second_string, int first_int, int second_int);
	string get_first_string();
	string get_second_string();
	int get_second_int();
	int get_first_int();
	friend istream& operator>>(istream& input, Entity& entity);



};
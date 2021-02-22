#pragma once
#include "Domain.h"
#include <cmath>

Bill::Bill(string name, string code, float sum,bool ispaid)
{

	this->name = name;
	this->code = code;
	this->sum = sum;
	this->ispaid = ispaid;
}

string Bill::get_name()
{
	return this->name;
}

string Bill::get_code()
{
	return this->code;
}

float Bill::get_sum()
{
	return this->sum;
}

bool Bill::get_ispaid()
{
	return this->ispaid;
}
istream& operator>>(istream& input, Bill& bill)
{
	string line;
	getline(input, line);

	if (line.size() == 0)
	{
		return input;
	}

	int position = line.find("; ");
	string name = line.substr(0, position);
	line.erase(0, position + 2);
	position = line.find("; ");
	string code_string = line.substr(0, position);
	line.erase(0, position + 2);
	position = line.find("; ");
	string sum_string = line.substr(0,position);
	float sum = stof(sum_string);
	line.erase(0, position + 2);
	string is_paid_string = line;
	bool ispaid=true;
	if (is_paid_string == "true")
	{
		ispaid = true;
	}
	else
	{
		ispaid = false;
	}



	bill = Bill(name,code_string,sum,ispaid);

	return input;
}

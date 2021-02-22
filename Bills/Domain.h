#pragma once
#include <string>
#include <iostream>
#include <vector>
using std::cout;
using std::string;
using std::ostream;
using std::istream;
using std::getline;
using std::vector;

class Bill
{

private:

	string name;
	string code;
	bool ispaid;
	float sum;

public:

	Bill()
	{

	};

	Bill(string name, string code, float sum,bool ispaid);
	string get_name();
	string get_code();
	float get_sum();
	bool get_ispaid();
	friend istream& operator>>(istream& input, Bill& bill);
	




};
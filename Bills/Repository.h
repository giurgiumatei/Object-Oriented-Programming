#pragma once
#include "Domain.h"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class Repository
{
public:
	string file_location;


	Repository()
	{

	};

	Repository(string file_location) :file_location{ file_location } {};
	vector<Bill>read_from_file();
	vector<Bill> get_data();



};


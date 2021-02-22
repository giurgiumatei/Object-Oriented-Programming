#pragma once
#include "Domain.h"
#include <vector>
#include <set>
#include <fstream>
using namespace std;
class Repository
{

public:

	string file_location;

	Repository()
	{

	};
	Repository(string file_location) :file_location{ file_location } {};
	vector<Vegetable> read_from_file();
	void write_to_file(vector<Vegetable> vegetable_list);
	vector<Vegetable> get_data();
	set<string> get_families();

};


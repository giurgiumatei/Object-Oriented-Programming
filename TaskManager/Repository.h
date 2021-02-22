#pragma once
#include "Domain.h"
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;


class Repository
{

public:

	string file_location;

	Repository()
	{

	};
	Repository(string file_location) :file_location{ file_location } {};
	vector<Task> read_from_file();
	void write_to_file(vector<Task> task_list);
	vector<Task> get_data();


};
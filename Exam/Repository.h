#pragma once
#include "Domain.h"
#include <vector>
#include <fstream>


class Repository
{

public:
	string file_location;

	Repository()
	{

	};
	Repository(string file_location) :file_location{ file_location } {};
	vector<Entity> read_from_file();
	vector<Entity> get_data();


};


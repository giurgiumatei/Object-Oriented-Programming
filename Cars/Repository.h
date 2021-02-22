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
	vector<Car> read_from_file();
	vector<Car> get_data();
	

};
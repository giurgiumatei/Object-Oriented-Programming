#pragma once
#include "Repository.h"


class Controller
{


private:
	Repository repository;

public:  
	Controller(Repository repository) :repository{ repository } {};
	Controller()
	{

	};

	vector<Car> get_data();
	vector<Car> get_data_sorted();
	int get_number_of_cars_filtered_by_name(string name);
	




};

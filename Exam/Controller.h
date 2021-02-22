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


	vector<Entity> get_data();
	vector<Entity> get_data_sorted();


};


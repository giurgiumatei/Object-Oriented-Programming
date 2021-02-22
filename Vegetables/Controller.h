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

	vector<Vegetable> get_data();
	set<string> get_families();



};
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


	vector<Bill> get_data();

	vector<Bill>get_sorted_data();
	



};
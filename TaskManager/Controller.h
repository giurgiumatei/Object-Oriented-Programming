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

	vector<Task> get_data();
	int show_total_duration_by_priority(int priority);



};
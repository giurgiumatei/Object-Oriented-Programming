#include "Controller.h"

vector<Vegetable> Controller::get_data()
{
	return this->repository.get_data();
}

set<string> Controller::get_families()
{
	return this->repository.get_families();
}

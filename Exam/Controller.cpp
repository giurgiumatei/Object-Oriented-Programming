#include "Controller.h"
#include <algorithm>


vector<Entity> Controller::get_data()
{
	return this->repository.get_data();
}


bool sorting_criteria(Entity first_entity, Entity second_entity)
{
	return first_entity.get_first_int() < second_entity.get_first_int();
}



vector<Entity> Controller::get_data_sorted()
{
	vector<Entity> entity_list = this->repository.get_data();
	sort(entity_list.begin(), entity_list.end(), sorting_criteria);

	return entity_list;
}


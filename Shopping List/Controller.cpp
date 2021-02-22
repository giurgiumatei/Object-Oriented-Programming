#include "Controller.h"

void Controller::add(Item item)
{
	this->repository.add(item);
}

void Controller::remove(Item item)
{
	this->repository.remove(item);
}

vector<Item> Controller::get_shopping_list()
{
	return this->repository.get_shopping_list();
}

vector<Item> Controller::filter(string category)
{

	if (category == "")
	{
		return repository.get_shopping_list();
	}

	vector<Item> filtered_list;
	vector<Item> shopping_list = repository.get_shopping_list();

	for (auto item : shopping_list)
	{
		if (item.get_category() == category)
		{
			filtered_list.push_back(item);
		}
	}

	return filtered_list;
}

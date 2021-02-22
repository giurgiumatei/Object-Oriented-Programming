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

	void add(Item item);
	void remove(Item item);
	vector<Item> get_shopping_list();
	vector<Item> filter(string category);


};


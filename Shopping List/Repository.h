#pragma once
#include "Domain.h"
#include <vector>
using std::vector;

class Repository
{
public:
	string file_location;
	

	vector<Item> read_from_file();
	void write_to_file(vector<Item> item_list);
	void add(Item item);
	void remove(Item item);


	Repository()
	{

	};

	Repository(string file_location) :file_location{ file_location } {};
    vector<Item> get_shopping_list();
   

};
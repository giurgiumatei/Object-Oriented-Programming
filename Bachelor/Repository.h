#pragma once
#include <vector>
#include "Student.h"


template <class TElem>

class Repository
{

private:
	vector<TElem> items;
	string file_name;


public:

	Repository(string file_name = "") :file_name{ file_name }
	{
		this->read_from_file();
	}

	vector<TElem> get_items()
	{
		return this->items;
	}

	void read_from_file()
	{
		ifstream filein(file_name);
		TElem item;
		while (fin >> item)
		{
			items.push_back(item);
		}
	}
};
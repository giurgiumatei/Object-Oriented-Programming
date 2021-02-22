#pragma once
#include "Answer.h"
#include "Question.h"


using namespace std;

template <class TElem>
class Repository
{
private:
	std::vector<TElem> items;
	std::string file_name;

public:
	Repository(std::string file_name = "") : file_name{ file_name }
	{
		this->read_from_file();
	}

	std::vector<TElem> get_items()
	{
		return this->items;
	}

	void read_from_file()
	{
		ifstream fileIn(file_name);
		TElem item;
		while (fileIn >> item)
		{
			items.push_back(item);
		}
	}

	void add_element(TElem new_element)
	{
		this->items.push_back(new_element);
	}

	void update_element(int index, TElem new_element)
	{
		this->items.at(index) = new_element;
	}
};

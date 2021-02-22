#pragma once
#include "Programmer.h"
#include "Task.h"

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

	void write_to_file()
	{
		ofstream fileOut(file_name);
		for (auto item : items)
		{
			fileOut << item;
		}

		fileOut.close();
	}

	void add_element(TElem new_element)
	{
		this->items.push_back(new_element);
		this->write_to_file();
	}

	void delete_element(int index)
	{
		this->items.erase(items.begin() + index);
		this->write_to_file();
	}

	void update_element(int index, TElem new_element)
	{
		this->items.at(index) = new_element;
		this->write_to_file();
	}
};

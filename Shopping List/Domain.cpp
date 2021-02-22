#include "Domain.h"


Item::Item(string category, string name, int quantity)
{
    this->category = category;
    this->name = name;
    this->quantity = quantity;
}

string Item::get_category() const
{
    return this->category;
}

void Item::set_category(string category)
{
    this->category = category;
}

string Item::get_name() const
{
    return this->name;
}

void Item::set_name(string name)
{
    this->name = name;
}

int Item::get_quantity() const
{
    return this->quantity;
}

void Item::set_quantity(int quantity)
{
    this->quantity = quantity;
}

istream& operator>>(istream& input, Item& item)
{
	string line;
	getline(input, line);

	if (line.size() == 0)
	{
		return input;
	}

	int position = line.find(" | ");
	string category = line.substr(0, position);
	line.erase(0, position + 3);
	position = line.find(" | ");
	string name = line.substr(0, position);
	line.erase(0, position + 3);
	string quantity_string = line;
	int quantity = stoi(quantity_string);

	item = Item(category, name, quantity);

	return input;
}

ostream& operator<<(ostream& output, Item& item)
{
	output << item.get_category() << " | " << item.get_name() << " | " << item.get_quantity()<< "\n";
	return output;
}

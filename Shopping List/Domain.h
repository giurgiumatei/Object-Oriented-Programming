#pragma once
#include <string>
#include <iostream>
#include <vector>
using std::cout;
using std::string;
using std::ostream;
using std::istream;
using std::getline;
using std::vector;

class Item
{

private:
	string category;
	string name;
	int quantity;



public:

    Item()
    {

    };
    Item(string category, string name, int quantity);
    string get_category() const;
    void set_category(string category);

    string get_name() const;
    void set_name(string name);

    int get_quantity() const;
    void set_quantity(int quantity);
    friend istream& operator>>(istream& input, Item& movie);
    friend ostream& operator<<(ostream& output, Item& movie);

};
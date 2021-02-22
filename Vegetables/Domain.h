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

class Vegetable
{
private:
    string family;
    string name;
    string parts;


public:
    Vegetable()
    {

    };
    Vegetable(string family, string name, string parts);
    string get_family();
    string get_name();
    string get_parts();
    friend istream& operator>>(istream& input, Vegetable& vegetable);
    friend ostream& operator<<(ostream& output, Vegetable& vegetable);

};
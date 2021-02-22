#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

  
class Car
{

private:
    string manufacturer;
    string model;
    int year;
    string color;

public:
    Car()
    {

    };

    Car(string manufacturer, string model, int year, string color) :
        manufacturer(manufacturer), model(model), year(year), color(color) {};

    string get_manufacturer();
    string get_model();
    string get_color();
    int get_year();
    friend istream& operator>>(istream& input, Car& car);



};

#include "Domain.h"

string Car::get_manufacturer()
{
	return this->manufacturer;
}
  
string Car::get_model()
{
	return this->model;
}

string Car::get_color()
{
	return this->color;
}

int Car::get_year()
{
	return this->year;
}

istream& operator>>(istream& input, Car& car)
{
	string line;
	getline(input, line);

	if (line.size() == 0)
	{
		return input;
	}

	int position = line.find(" | ");
	string manufacturer = line.substr(0, position);
	line.erase(0, position + 3);
	position = line.find(" | ");
	string model = line.substr(0, position);
	line.erase(0, position + 3);
	position = line.find(" | ");
	string year_string = line.substr(0, position);
	int year = stoi(year_string);
	line.erase(0, position + 3);
	string color = line;


	car = Car(manufacturer, model, year,color);

	return input;
}

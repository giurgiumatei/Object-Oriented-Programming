#include "Controller.h"
#include <algorithm>
vector<Car> Controller::get_data()
{
	return this->repository.get_data();
}





bool sorting_criteria(Car first_car, Car second_car)
{
	return first_car.get_manufacturer() < second_car.get_manufacturer();
}


vector<Car> Controller::get_data_sorted()
{
	vector<Car> cars_list = this->repository.get_data();
	sort(cars_list.begin(), cars_list.end(), sorting_criteria);

	return cars_list;
}


/*This function gets the names from the repository and parses the vector of names, 
incrementing and then returning a counter for how many cars does the manufacturer
given as parameter to the function has in the list */
int Controller::get_number_of_cars_filtered_by_name(string name)
{
	int counter = 0;
	vector<Car> cars_list = this->repository.get_data();
	for (auto car : cars_list) 
	{
		if (car.get_manufacturer() == name) 
		{
			counter++;
		}
	}

	return counter;
}

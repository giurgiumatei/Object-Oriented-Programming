#include "Repository.h"

vector<Car> Repository::read_from_file()
{
    ifstream file_reader(this->file_location);

    Car new_car;

    vector<Car> items_list;

    while (file_reader >> new_car)
    {
        items_list.push_back(new_car);

    }

    file_reader.close();

    return items_list;
}
  
vector<Car> Repository::get_data()
{
    return this->read_from_file();
}

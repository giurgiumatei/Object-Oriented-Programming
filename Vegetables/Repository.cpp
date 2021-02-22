#include "Repository.h"
#include <iostream>

vector<Vegetable> Repository::read_from_file()
{
    ifstream file_reader(this->file_location);

   Vegetable new_vegetable;

    vector<Vegetable> items_list;

    while (file_reader >> new_vegetable)
    {
        items_list.push_back(new_vegetable);

    }

    file_reader.close();

    return items_list;
}

void Repository::write_to_file(vector<Vegetable> vegetable_list)
{
    ofstream file_writer(this->file_location);



    for (auto vegetable : vegetable_list)
    {
        file_writer << vegetable;
    }

    file_writer.close();
}

vector<Vegetable> Repository::get_data()
{
    return this->read_from_file();
}

set<string> Repository::get_families()
{
    set<string> families;
    vector<Vegetable> vegetable_list = this->read_from_file();


    for (auto vegetable : vegetable_list)
    {
        families.insert(vegetable.get_family());
    }
    
    return families;
}

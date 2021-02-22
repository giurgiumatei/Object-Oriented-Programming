#include "Repository.h"

vector<Entity> Repository::read_from_file()
{
    ifstream file_reader(this->file_location);

    Entity new_entity;

    vector<Entity> items_list;

    while (file_reader >> new_entity)
    {
        items_list.push_back(new_entity);

    }

    file_reader.close();

    return items_list;
}

vector<Entity> Repository::get_data()
{
    return this->read_from_file();
}

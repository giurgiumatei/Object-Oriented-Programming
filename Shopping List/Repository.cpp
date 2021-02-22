#include "Repository.h"
#include <fstream>
using namespace std;
vector<Item> Repository::read_from_file()
{
    ifstream file_reader(this->file_location);

    Item new_item;

    vector<Item> items_list;

    while (file_reader >> new_item)
    {
        items_list.push_back(new_item);

    }

    file_reader.close();

    return items_list;

}
void Repository::write_to_file(vector<Item> item_list)
{
    ofstream file_writer(this->file_location);



    for (auto item : item_list)
    {
        file_writer << item;
    }

    file_writer.close();

}
void Repository::add(Item item)
{
    vector<Item> item_list = this->read_from_file();



    item_list.push_back(item);

    

    this->write_to_file(item_list);


}
void Repository::remove(Item item)
{
    string name = item.get_name();
    vector<Item> item_list = this->read_from_file();

   
    int index = 0;
    for (auto item_from_list : item_list)
    {
        if (item_from_list.get_name() == name)
        {
            item_list.erase(item_list.begin() + index);
            this->write_to_file(item_list);
            return;
        }
        index++;
    }
    

}
vector<Item> Repository::get_shopping_list() 
{
    vector<Item> shopping_list = this->read_from_file();
    return shopping_list;
}


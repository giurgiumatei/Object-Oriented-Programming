#include "Repository.h"

vector<Bill> Repository::read_from_file()
{
    ifstream file_reader(this->file_location);

    Bill new_bill;

    vector<Bill> bills_list;

    while (file_reader >> new_bill)
    {
        bills_list.push_back(new_bill);

    }

    file_reader.close();

    return bills_list;
}

vector<Bill> Repository::get_data()
{
    return this->read_from_file();
}


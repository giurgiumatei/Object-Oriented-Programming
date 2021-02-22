#include "User.h"

string User::getName() const
{
    return name;
}

void User::setName(string name)
{
    this->name = name;
}

string User::getType() const
{
    return type;
}

void User::setType(string type)
{
    this->type = type;
}

ifstream& operator>>(ifstream& input, User& user)
{
    string line;
    Utilities utilities;



    if (getline(input, line))
    {
        vector<string> parameters = utilities.split_parameters(line, '|');
        user.name = parameters[0];
        user.type = parameters[1];

        return input;
    }
    else return input;
}


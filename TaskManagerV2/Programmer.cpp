#include "Programmer.h"

string Programmer::getName() const
{
    return name;
}

void Programmer::setName(string name)
{
    this->name = name;
}

int Programmer::getId() const
{
    return id;
}

void Programmer::setId(int id)
{
    this->id = id;
}

ifstream& operator>>(ifstream& input, Programmer& programmer)
{

    string line;
    Utilities utilities;



    if (getline(input, line))
    {
        vector<string> parameters = utilities.split_parameters(line, '|');
        programmer.name =parameters[0];
        programmer.id = stoi(parameters[1]);
        
        return input;
    }
    else return input;
}

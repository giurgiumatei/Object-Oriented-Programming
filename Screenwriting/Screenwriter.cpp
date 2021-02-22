#include "Screenwriter.h"

string Screenwriter::getName() const
{
    return name;
}

void Screenwriter::setName(string name)
{
    this->name = name;
}

string Screenwriter::getExpertize() const
{
    return expertize;
}

void Screenwriter::setExpertize(string expertize)
{
    this->expertize = expertize;
}

ifstream& operator>>(ifstream& input, Screenwriter& screenwriter)
{
    string line;
    Utilities utilities;



    if (getline(input, line))
    {
        vector<string> parameters = utilities.split_parameters(line, '|');
        screenwriter.name = parameters[0];
        screenwriter.expertize = parameters[1];

        return input;
    }
    else return input;
}

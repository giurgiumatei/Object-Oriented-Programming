#include "Astronomer.h"

string Astronomer::getName() const
{
    return name;
}

void Astronomer::setName(string name)
{
    this->name = name;
}

string Astronomer::getConstelation() const
{
    return constelation;
}

void Astronomer::setConstelation(string constelation)
{
    this->constelation = constelation;
}

ifstream& operator>>(ifstream& input, Astronomer& astronomer)
{
    
        string line;
        Utilities utilities;



        if (getline(input, line))
        {
            vector<string> parameters = utilities.split_parameters(line, '|');
            astronomer.name = parameters[0];
            astronomer.constelation = parameters[1];
            
            return input;
        }
        else return input;
    
}

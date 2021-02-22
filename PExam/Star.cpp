#include "Star.h"

string Star::getName() const
{
    return name;
}

void Star::setName(string name)
{
    this->name = name;
}

string Star::getConstelation() const
{
    return constelation;
}

void Star::setConstelation(string constelation)
{
    this->constelation = constelation;
}

int Star::getRa() const
{
    return ra;
}

void Star::setRa(int ra)
{
    this->ra = ra;
}

int Star::getDec() const
{
    return dec;
}

void Star::setDec(int dec)
{
    this->dec = dec;
}

int Star::getDiameter() const
{
    return diameter;
}

void Star::setDiameter(int diameter)
{
    this->diameter = diameter;
}

ifstream& operator>>(ifstream& input, Star& star)
{

    string line;
    Utilities utilities;



    if (getline(input, line))
    {
        vector<string> parameters = utilities.split_parameters(line, '|');
        star.name = parameters[0];
        star.constelation = parameters[1];
        star.ra =stoi( parameters[2]);
        star.dec = stoi(parameters[3]);
        star.diameter = stoi(parameters[4]);

        return input;
    }
    else return input;
}

ofstream& operator<<(ofstream& output, Star& star)
{
    output << star.getName() << "|" << star.getConstelation() << "|" << star.getRa() << "|" << star.getDec() << "|" << star.getDiameter()<< "\n";
    return output;
}

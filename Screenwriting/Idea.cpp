#include "Idea.h"

string Idea::getStatus() const
{
    return status;
}

void Idea::setStatus(string status)
{
    this->status = status;
}

string Idea::getCreator() const
{
    return creator;
}

void Idea::setCreator(string creator)
{
    this->creator = creator;
}

int Idea::getAct() const
{
    return act;
}

void Idea::setAct(int act)
{
    this->act = act;
}

ifstream& operator>>(ifstream& input, Idea& idea)
{
    string line;
    Utilities utilities;



    if (getline(input, line))
    {
        vector<string> parameters = utilities.split_parameters(line, '|');
        idea.description = parameters[0];
        idea.status = parameters[1];
        idea.creator = parameters[2];
        idea.act = stoi(parameters[3]);

        return input;
    }
    else return input;
}

ofstream& operator<<(ofstream& output, Idea& idea)
{
    output << idea.getDescription()<<"|"<<idea.getStatus() << "|" << idea.getCreator() << "|" << idea.getAct() << "\n";
    return output;
}

string Idea::getDescription() const
{
    return description;
}

void Idea::setDescription(string description)
{
    this->description = description;
}


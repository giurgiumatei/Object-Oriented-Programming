#include "Participant.h"

string Participant::getName() const
{
    return name;
}

void Participant::setName(string name)
{
    this->name = name;
}

int Participant::getScore() const
{
    return score;
}

void Participant::setScore(int score)
{
    this->score = score;
}

ifstream& operator>>(ifstream& input, Participant& participant)
{
    string line;
    Utilities utilities;



    if (getline(input, line))
    {
        participant.name = line;
        participant.score = 0;

        return input;
    }
    else return input;
}

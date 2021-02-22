#include "Answer.h"

int Answer::getId() const
{
    return id;
}

void Answer::setId(int id)
{
    this->id = id;
}

int Answer::getQuestionid() const
{
    return question_id;
}

void Answer::setQuestionid(int questionid)
{
    question_id = questionid;
}

int Answer::getVotes() const
{
    return votes;
}

void Answer::setVotes(int votes)
{
    this->votes = votes;
}

string Answer::getName() const
{
    return name;
}

void Answer::setName(string name)
{
    this->name = name;
}

string Answer::getText() const
{
    return text;
}

void Answer::setText(string text)
{
    this->text = text;
}

vector<string> Answer::split_parameters(string, char delimiter)
{
    return vector<string>();
}

ifstream& operator>>(ifstream& input, Answer& respond)
{
    string line;
    Utilities utilities;

    if (getline(input, line))
    {
        vector<string> parameters = utilities.split_parameters(line,'|');
        respond.id = stoi(parameters[0]);
        respond.question_id = stoi(parameters[1]);
        respond.name = parameters[2];
        respond.text = parameters[3];
        respond.votes = stoi(parameters[4]);
        return input;
    }
    else
    {
        return input;
    }
}

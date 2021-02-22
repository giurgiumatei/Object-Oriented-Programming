#include "Question.h"

int Question::getId() const
{
    return id;
}

void Question::setId(int id)
{
    this->id = id;
}

string Question::getText() const
{
    return text;
}

void Question::setText(string text)
{
    this->text = text;
}

string Question::getUsername() const
{
    return user_name;
}

void Question::setUsername(string username)
{
    user_name = username;
}

ifstream& operator>>(ifstream& input, Question& question)
{
    string line;
    Utilities utilities;



    if (getline(input, line))
    {
        vector<string> parameters = utilities.split_parameters(line, '|');
        question.id = stoi(parameters[0]);
        question.text = parameters[1];
        question.user_name = parameters[2];
        return input;
    }
    else return input;
}

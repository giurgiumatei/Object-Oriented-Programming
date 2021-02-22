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

string Question::getCorrectanswer() const
{
    return correct_answer;
}

void Question::setCorrectanswer(string correctanswer)
{
    correct_answer = correctanswer;
}

int Question::getScore() const
{
    return score;
}

void Question::setScore(int score)
{
    this->score = score;
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
        question.correct_answer = parameters[2];
        question.score = stoi(parameters[3]);

        return input;
    }
    else return input;
}

ofstream& operator<<(ofstream& output, Question& question)
{
    output << question.getId() << "|" << question.getText() << "|" << question.getCorrectanswer() << "|" << question.getScore() << "\n";
    return output;
}

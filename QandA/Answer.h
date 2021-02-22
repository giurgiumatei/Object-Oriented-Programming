#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Utilities.h"
using namespace std;


class Answer
{

private:
	int id, question_id, votes;
	string name, text;
public:
	Answer(int id, int question_id, int votes, string name, string text) :id{ id }, question_id{ question_id }, votes{ votes }, name{ name }, text{ text }{}
    Answer()
    {

    }

    int getId() const;
    void setId(int id);

    int getQuestionid() const;
    void setQuestionid(int questionid);

    int getVotes() const;
    void setVotes(int votes);

    string getName() const;
    void setName(string name);

    string getText() const;
    void setText(string text);

    vector<string> split_parameters(string, char delimiter);
    friend ifstream& operator>> (ifstream& input, Answer& respond);

};


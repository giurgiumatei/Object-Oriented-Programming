#pragma once
#include "Utilities.h"
#include <iostream>
#include <fstream>

class Question
{
private:
	int id;
	string text;
	string correct_answer;
	int score;

public:
	Question()
	{


	}
	Question(int id,string text,string correct_answer,int score):
		id{ id }, text{ text }, correct_answer{ correct_answer }, score{ score }{}


    int getId() const;
    void setId(int id);

    string getText() const;
    void setText(string text);

    string getCorrectanswer() const;
    void setCorrectanswer(string correctanswer);

    int getScore() const;
    void setScore(int score);
	friend ifstream& operator>> (ifstream& input, Question& question);
	friend ofstream& operator<< (ofstream& output, Question& question);

};


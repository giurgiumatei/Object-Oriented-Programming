#pragma once
#include "Utilities.h"
#include <iostream>
#include <fstream>

class Participant
{
private:
	string name;
	int score;
public:
	Participant()
	{

	}
	Participant(string name,int score):
		name{ name }, score{ score }{}


    string getName() const;
    void setName(string name);

    int getScore() const;
    void setScore(int score);

	friend ifstream& operator>> (ifstream& input, Participant& participant);

};


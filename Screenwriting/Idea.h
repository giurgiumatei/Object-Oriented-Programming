#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "Utilities.h"
using namespace std;


class Idea
{
private:
	string description;
	string status;
	string creator;
	int act;

public:
	Idea()
	{

	}
	Idea(string description, string status, string creator, int act) :description{description},status { status }, creator{ creator }, act{ act }{}

    string getStatus() const;
    void setStatus(string status);

    string getCreator() const;
    void setCreator(string creator);

    int getAct() const;
    void setAct(int act);

	friend ifstream& operator>> (ifstream& input, Idea& idea);
	friend ofstream& operator<< (ofstream& output, Idea& idea);
    string getDescription() const;
    void setDescription(string description);

};


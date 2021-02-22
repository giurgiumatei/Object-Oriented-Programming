#pragma once
#include "Utilities.h"
#include <iostream>
#include <fstream>


class Issue
{

private:

	string description;
	string status;
	string reporter;
	string solver;

public:

	Issue()
	{

	}

	Issue(string description, string status, string reporter, string solver):
		description{ description }, status{ status }, reporter{ reporter }, solver{ solver }{}


    string getDescription() const;
    void setDescription(string description);

    string getStatus() const;
    void setStatus(string status);

    string getReporter() const;
    void setReporter(string reporter);

    string getSolver() const;
    void setSolver(string solver);
	friend ifstream& operator>> (ifstream& input, Issue& issue);
	friend ofstream& operator<< (ofstream& output, Issue& issue);

};


#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "Utilities.h"
using namespace std;
class Task
{
private:
	string description;
	string status;
	int id;
     

public:
    Task()
    {

    }
    Task(string description, string status, int id) :description{ description }, status{ status }, id{ id }{}
    
    string getDescription() const;
    void setDescription(string description);

    string getStatus() const;
    void setStatus(string status);

    int getId() const;
    void setId(int id);
    friend ifstream& operator>> (ifstream& input, Task& task);
    friend ofstream& operator<< (ofstream& output, Task& task);

};


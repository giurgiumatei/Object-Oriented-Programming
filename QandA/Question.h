#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Utilities.h"
using namespace std;


class Question
{
private:
	int id;
	string text;
	string user_name;
public:
    Question(int id, string text, string user_name) :id{ id }, text{ text }, user_name{ user_name }{}

    Question()
    {

    }
public:
    int getId() const;
    void setId(int id);

    string getText() const;
    void setText(string text);

    string getUsername() const;
    void setUsername(string username);
    friend ifstream& operator>> (ifstream& input, Question& question);

};


#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "Utilities.h"
using namespace std;

class Star
{
private:
	string name;
	string constelation;
	int ra;
	int dec;
	int diameter;
public:
	Star()
	{

	}
	Star(string name,string constelation,int ra,int dec,int diameter):
		name{ name }, constelation{ constelation }, ra{ ra }, dec{ dec }, diameter{ diameter }{}
    string getName() const;
    void setName(string name);

    string getConstelation() const;
    void setConstelation(string constelation);

    int getRa() const;
    void setRa(int ra);

    int getDec() const;
    void setDec(int dec);

    int getDiameter() const;
    void setDiameter(int diameter);
	friend ifstream& operator>> (ifstream& input, Star& star);
	friend ofstream& operator<< (ofstream& output, Star& star);

};


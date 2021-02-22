#pragma once
#include <string>
#include <iostream>
#include <vector>
using std::cout;
using std::string;
using std::ostream;
using std::istream;
using std::getline;
using std::vector;

class Task
{
private:
	string description;
	int duration;
	int priority;


public:
    Task()
    {

    };
    Task(string description, int duration, int priority);
    string get_description() const;
    void set_description(string description);

    int get_duration() const;
    void set_duration(int duration);

    int get_priority() const;
    void set_priority(int priority);
    friend istream& operator>>(istream& input, Task& movie);
    friend ostream& operator<<(ostream& output, Task& movie);

};
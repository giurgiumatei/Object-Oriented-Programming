#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Student
{
private:
	string id;
	string name;
	string email;
	int year;
	string title;
	string coordinator;

public:

	Student(string id, string name, string email, int year, string title, string coordinator) :id{ id }, name{ name }, email{ email }, year{ year }, title{ title }, coordinator{ coordinator }{}



public:
    string get_id() ;
   

    string get_name();
   

    string get_email();
    void set_email(string email);

    int get_year();

    string get_title();
    void set_title(string title);

    string get_coordinator();
    void set_coordinator(string coordinator);

    friend istream& operator>>(istream& input, Student& student);
    

};


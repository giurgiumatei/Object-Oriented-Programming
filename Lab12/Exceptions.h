#pragma once
#include <exception>
#include <string>
using std::string;
using std::exception;

class Repository_Exception : public exception 
{
	string message;
public:
	Repository_Exception(string message);
	string get_message();
};

class Validator_Exception : public exception 
{
	string message;
public:
	Validator_Exception(string message);
	string get_message();
};

class Input_Exception : public exception 
{
	string message;
public:
	Input_Exception(string message);
	string get_message();
};


class File_Exception : public exception 
{
	string message;
public:
	File_Exception(string message);
	string get_message();
};
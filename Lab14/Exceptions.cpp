#pragma once
#include "Exceptions.h"

Repository_Exception::Repository_Exception(string message) :message(message) {}

string Repository_Exception::get_message()
{
	return this->message;
}

Validator_Exception::Validator_Exception(string message) : message(message) {}

string Validator_Exception::get_message()
{
	return this->message;
}

Input_Exception::Input_Exception(string message) : message(message) {}

string Input_Exception::get_message()
{
	return this->message;
}

File_Exception::File_Exception(string message) : message(message) {}

string File_Exception::get_message()
{
	return this->message;
}

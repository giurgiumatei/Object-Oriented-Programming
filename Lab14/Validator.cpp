#pragma once
#include "Validator.h"

void Validator::validate_title(string given_title)
{
	if (given_title == "")
		throw Validator_Exception("Invalid Title!");
}

void Validator::validate_genre(string given_genre)
{
	if (given_genre == "")
	{
		throw Validator_Exception("Invalid Genre!");
	}
}

void Validator::validate_year_of_release(unsigned int given_year_of_release)
{
	if (given_year_of_release > 2020)
	{
		throw Validator_Exception("Invalid Year!");
	}
}

void Validator::validate_likes(unsigned int given_likes)
{
	if (given_likes < 0)
	{
		throw Validator_Exception("Invalid Number of Likes!");
	}


}

void Validator::validate_trailer(string given_trailer)
{
	if (given_trailer == "")
		throw Validator_Exception("Invalid Trailer!");


}

void Validator::validate_data(string given_title, string given_genre, unsigned int given_year_of_release, unsigned int given_likes, string given_trailer)
{
	string exception = "";
	try {
		validate_title(given_title);
	}
	catch (Validator_Exception& validator_exception) {
		exception += validator_exception.get_message();
		exception += "\n";
	}
	try {
		validate_genre(given_genre);
	}
	catch (Validator_Exception& validator_exception) {
		exception += validator_exception.get_message();
		exception += "\n";
	}
	try {
		validate_year_of_release(given_year_of_release);
	}
	catch (Validator_Exception& validator_exception) {
		exception += validator_exception.get_message();
		exception += "\n";
	}
	try {
		validate_likes(given_likes);
	}
	catch (Validator_Exception& validator_exception) {
		exception += validator_exception.get_message();
		exception += "\n";
	}
	try {
		validate_trailer(given_genre);
	}
	catch (Validator_Exception& validator_exception) {
		exception += validator_exception.get_message();
		exception += "\n";
	}
	if (exception != "")
	{
		throw Validator_Exception(exception);
	}
}

void Validator::validate_movie(string trailer)
{
	string exception = "";

	try
	{
		for (auto trailer_from_repository : this->trailers)
		{
			if (trailer_from_repository == trailer)
			{

				throw Validator_Exception("Movie already exists in repository!");
			}
		}
	}


	catch (Validator_Exception& validator_exception)
	{

		exception += validator_exception.get_message();
		exception += "\n";
	}

}

void Validator::add_to_trailers(string trailer)
{
	this->trailers.push_back(trailer);
}

void Validator::remove_from_trailers(string trailer)
{
	int index = 0;
	for (auto trailer_from_repository : this->trailers)
	{
		if (trailer_from_repository == trailer)
		{
			this->trailers.erase(this->trailers.begin() + index);

		}
		index++;
	}
}


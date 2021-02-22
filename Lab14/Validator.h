#pragma once
#include <string>
#include "Exceptions.h"
#include <vector>
#include "Domain.h"
using std::string;
using std::vector;
class Validator
{

private:

	void validate_title(string given_title);
	void validate_genre(string given_genre);
	void validate_year_of_release(unsigned int given_year_of_release);
	void validate_likes(unsigned int given_likes);
	void validate_trailer(string given_trailer);

public:
	vector<string> trailers;
	void validate_data(string  given_title, string  given_genre, unsigned int given_year_of_release, unsigned int given_likes, string given_trailer);
	void validate_movie(string trailer);
	void add_to_trailers(string trailer);
	void remove_from_trailers(string trailer);
};




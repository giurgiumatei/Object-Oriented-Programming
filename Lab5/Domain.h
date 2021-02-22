#pragma once
#include <string>
using std::string;


class Movie
{
private:
	string title, genre,  trailer;
	unsigned int year_of_release, likes;

public:

	Movie();
	Movie(string& title, string& genre, unsigned int& year_of_release, unsigned int& likes, string& trailer);



	string get_title();


	string get_genre();

	string get_trailer();

	unsigned int get_year_of_release();

	unsigned int get_likes();

	void set_genre(string new_genre);

	void set_trailer(string new_trailer);

	void set_year_of_release(unsigned int new_year_of_release);


	void set_likes(unsigned int new_likes);

	bool operator==(Movie movie);

	

};
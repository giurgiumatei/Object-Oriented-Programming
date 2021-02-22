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



	string get_title()
	{
		return this->title;
	}


	string get_genre()
	{
		return this->genre;

	}

	string get_trailer()
	{
		return this->trailer;
	}

	unsigned int get_year_of_release()
	{
		return this->year_of_release;

	}

	unsigned int get_likes()
	{

		return this->likes;
	}

	void set_genre(string new_genre)
	{
		this->genre = new_genre;
	}

	void set_trailer(string new_trailer)
	{
		this->trailer = new_trailer;

	}

	void set_year_of_release(unsigned int new_year_of_release)
	{
		this->year_of_release = new_year_of_release;

	}


	void set_likes(unsigned int new_likes)
	{
		this->likes = new_likes;
	}

	

};
#include "Domain.h"


Movie::Movie() :title(""), genre(""), year_of_release(0), likes(0), trailer("") {}

Movie::Movie(string& title, string& genre, unsigned int& year_of_release,unsigned int& likes, string& trailer)
{

	this->title = title;
	this->genre = genre;
	this->year_of_release = year_of_release;
	this->likes = likes;
	this->trailer = trailer;


}

string Movie::get_title()
{
	return this->title;
}

string Movie::get_genre()
{
	return this->genre;

}

string Movie::get_trailer()
{
	return this->trailer;
}

unsigned int Movie::get_year_of_release()
{
	return this->year_of_release;

}

unsigned int Movie::get_likes()
{

	return this->likes;
}

void Movie::set_genre(string new_genre)
{
	this->genre = new_genre;
}

void Movie::set_trailer(string new_trailer)
{
	this->trailer = new_trailer;

}

void Movie::set_year_of_release(unsigned int new_year_of_release)
{
	this->year_of_release = new_year_of_release;

}

void Movie::set_likes(unsigned int new_likes)
{
	this->likes = new_likes;
}

bool Movie::operator==(Movie movie)
{
	if (this->get_title == movie.get_title())
	{
		return true;
	}

	return false;
		
}

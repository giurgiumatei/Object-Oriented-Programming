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
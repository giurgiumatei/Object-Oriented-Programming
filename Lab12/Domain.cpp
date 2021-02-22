#include "Domain.h"


Movie::Movie() :title(""), genre(""), year_of_release(0), likes(0), trailer("") {}

Movie::Movie(string& title, string& genre, unsigned int& year_of_release, unsigned int& likes, string& trailer)
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



ostream& operator<<(ostream& output, Movie &movie)
{
	output << movie.get_title() << "," << movie.get_genre() << "," << movie.get_year_of_release() << "," << movie.get_likes() << "," << movie.get_trailer() << "\n";
	return output;
}

istream& operator>>(istream& input, Movie& movie)
{
	string line ;
	getline(input, line);

	if (line.size() == 0)
	{
		return input;
	}

	int position = line.find(",");
	string title = line.substr(0, position);
	line.erase(0, position + 1);
	position = line.find(",");
	string genre = line.substr(0, position);
	line.erase(0, position + 1);
	position = line.find(",");
	string year = line.substr(0, position);
	unsigned int year_of_release = stoul(year);
	line.erase(0, position + 1);
	position = line.find(",");
	string number_of_likes = line.substr(0, position);
	unsigned int likes = stoul(number_of_likes);
	line.erase(0, position + 1);
	string trailer = line;

	movie= Movie(title, genre, year_of_release, likes, trailer);

	return input;

}

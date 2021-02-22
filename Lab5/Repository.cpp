#include "Repository.h"

bool Repository::add_movie(Movie movie)
{
	this->movies.add(movie);
	return true;
}

bool Repository::remove_movie(string title)
{
	this->movies.remove(title);
	return true;
}

bool Repository::update_movie(Movie movie)
{
	this->movies.update(movie);
	return true;
}

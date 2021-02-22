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

Movie* Repository::get_movies()
{
	return this->movies.get_elements_data();
}
int Repository::get_lenght_repository()
{
	return this->movies.get_lenght();
}

bool Repository::is_in_list_repository(string title)
{
	return this->movies.is_in_list(title);

}

DynamicVector<Movie> Repository::get_data_repository()
{
	return this->movies;

}

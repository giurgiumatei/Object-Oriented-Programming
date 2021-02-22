#include "Repository.h"

bool Repository::add_movie(Movie movie)
{
	this->movies.push_back(movie);
	this->validator.add_to_trailers(movie.get_trailer());
	return true;
}

bool Repository::remove_movie(string title)
{
	int index = 0;
	this->validator.remove_from_trailers(title);
	for (auto movie:this->movies)
	{
		if (movie.get_title() == title)
		{
			this->movies.erase(this->movies.begin() + index);
			return true;
		}
		index++;
	}
	
	
	return false;
}

bool Repository::update_movie(Movie movie)
{
	int index = 0;

	this->validator.add_to_trailers(movie.get_trailer());
	for (auto movie_loop : this->movies)
	{
		if (movie_loop.get_title() == movie.get_title())
		{
			this->validator.remove_from_trailers(movie_loop.get_title());
			this->movies[index] = movie;
			return true;}}
	

	return false;
}


int Repository::get_lenght_repository()
{
	return this->movies.size();
}

bool Repository::is_in_list_repository(string title)
{
	for (auto movie:this->movies)
	{
		if (movie.get_title() == title)
		{
			
			return true;}}


	return false;

}

vector<Movie> Repository::get_data_repository()
{
	return this->movies;

}

void Repository::display_watchlist()
{
	return;
}

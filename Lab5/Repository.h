#pragma once
#include "DynamicVector.h"

class Repository
{

private:

	DynamicVector<Movie> movies;


public:

	Repository() {};

	bool add_movie(Movie movie);

	bool remove_movie(string title);

	bool update_movie(Movie movie);

	Movie* get_movies()
	{
		return this->movies.get_elements_data();
	}

	int get_lenght_repository()
	{
		return this->movies.get_lenght();
	}

	bool is_in_list_repository(string title)
	{
		return this->movies.is_in_list(title);

	}
	DynamicVector<Movie> get_data_repository()
	{
		return this->movies;

	}


};
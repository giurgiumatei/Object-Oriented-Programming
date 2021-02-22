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

	Movie* get_movies();

	int get_lenght_repository();

	bool is_in_list_repository(string title);
	
	DynamicVector<Movie> get_data_repository();


};
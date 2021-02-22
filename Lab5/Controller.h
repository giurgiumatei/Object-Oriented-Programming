#pragma once
#include "Repository.h"


class Controller
{

private:

	Repository repository;
	Repository watchlist;

public:

	Controller(Repository repository, Repository watchlist) :repository{ repository }, watchlist{ watchlist } {}

	
	bool add_movie_controller(string title, string genre,unsigned int year_of_release,unsigned int likes, string trailer);

	bool remove_movie_controller(string title);

	bool update_movie_controller(string title, string genre,unsigned int year_of_release,unsigned int likes, string trailer);

	bool add_movie_watchlist(string title, string genre, unsigned int year_of_release, unsigned int likes, string trailer);

	int get_length_of_data();

	
	DynamicVector<Movie> get_data_controller()
	{
		return this->repository.get_data_repository();

	}

	DynamicVector<Movie> get_data_watchlist()
	{
		return this->watchlist.get_data_repository();

	}

	

};
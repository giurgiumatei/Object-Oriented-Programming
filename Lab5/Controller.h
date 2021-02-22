#pragma once
#include "Repository.h"


class Controller
{

private:

	Repository repository;

public:

	Controller(Repository repository) :repository{ repository } {}

	
	bool add_movie_controller(string title, string genre,unsigned int year_of_release,unsigned int likes, string trailer);

	bool remove_movie_controller(string title);

	bool update_movie_controller(string title, string genre,unsigned int year_of_release,unsigned int likes, string trailer);
	
	DynamicVector<Movie> get_data_controller()
	{
		return this->repository.get_data_repository();

	}

	

};
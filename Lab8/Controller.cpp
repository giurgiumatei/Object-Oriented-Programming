#pragma once
#include "Controller.h"

bool Controller::add_movie_controller(string title, string genre, unsigned int year_of_release, unsigned  int likes, string trailer)
{
	Movie new_movie = Movie(title, genre, year_of_release, likes, trailer);

	this->repository.add_movie(new_movie);

	return true;

}

bool Controller::remove_movie_controller(string title)
{
	if (this->repository.is_in_list_repository(title) == false)
	{
		return false;
	}


	this->repository.remove_movie(title);

	return true;


}

bool Controller::update_movie_controller(string title, string genre, unsigned int year_of_release, unsigned int likes, string trailer)
{
	if (this->repository.is_in_list_repository(title) == false)
	{
		return false;
	}

	Movie movie_replacement = Movie(title, genre, year_of_release, likes, trailer);

	this->repository.update_movie(movie_replacement);

	return true;
}

bool Controller::add_movie_watchlist(string title, string genre, unsigned int year_of_release, unsigned int likes, string trailer)
{
	Movie new_movie = Movie(title, genre, year_of_release, likes, trailer);

	this->watchlist.add_movie(new_movie);

	return true;
}

int Controller::get_length_of_data()
{
	return this->repository.get_lenght_repository();
}

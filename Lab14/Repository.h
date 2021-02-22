#pragma once
#include "Domain.h"
#include <vector>
#include "Validator.h"
using std::vector;


class Repository
{

private:

	vector<Movie> movies;
	Validator validator;

public:

	Repository() {};


	virtual bool add_movie(Movie movie);

	virtual bool remove_movie(string title);

	virtual bool update_movie(Movie movie);

	virtual int get_lenght_repository();

	virtual bool is_in_list_repository(string title);

	virtual vector<Movie> get_data_repository();

	virtual void display_watchlist();


};
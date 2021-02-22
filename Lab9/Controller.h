#pragma once
#include "Repository.h"
#include "FileRepository.h"
#include "CSVRepository.h"
#include "HTMLRepository.h"
#include "Validator.h"

class Controller
{

private:

	File_Repository repository;
	Repository* watchlist;
	Validator validator;
public:

	Controller(File_Repository repository, Repository* watchlist, Validator) :repository{ repository }, watchlist{ watchlist }, validator{ validator } {}


	bool add_movie_controller(string title, string genre, unsigned int year_of_release, unsigned int likes, string trailer);

	bool remove_movie_controller(string title);

	bool update_movie_controller(string title, string genre, unsigned int year_of_release, unsigned int likes, string trailer);

	bool add_movie_watchlist(string title, string genre, unsigned int year_of_release, unsigned int likes, string trailer);

	int get_length_of_data();


	vector<Movie> get_data_controller();

	vector<Movie> get_data_watchlist();



};
#pragma once
#include "Repository.h"
#include "FileRepository.h"
#include "CSVRepository.h"
#include "HTMLRepository.h"
#include "Validator.h"
#include "UndoBase.h"
#include "RedoBase.h"
#include "UndoAdd.h"
#include "UndoDelete.h"
#include "UndoUpdate.h"
#include "RedoAdd.h"
#include "RedoDelete.h"
#include "RedoUpdate.h"
class Controller
{

private:

	Repository* repository;
	Repository* watchlist;
	Validator validator;
	vector <UndoBaseClass*> undo_stack;
	vector <RedoBaseClass*> redo_stack;
public:

	Controller(Repository* repository, Repository* watchlist, Validator) :repository{ repository }, watchlist{ watchlist }, validator{ validator } {}


	bool add_movie_controller(string title, string genre, unsigned int year_of_release, unsigned int likes, string trailer);

	bool remove_movie_controller(string title);

	bool update_movie_controller(string title, string genre, unsigned int year_of_release, unsigned int likes, string trailer);

	bool add_movie_watchlist(string title, string genre, unsigned int year_of_release, unsigned int likes, string trailer);

	void add_movie_watchlist_by_title(string title);

	int get_length_of_data();

	void open_watchlist();

	vector<Movie> get_data_controller();

	vector<Movie> get_data_watchlist();

	void undo();

	void redo();

	Movie find_movie_by_title(string title);



};
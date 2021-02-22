#pragma once
#include "Controller.h"
#include <exception>
#include "Lab12\Lab12\Controller.h"

using std::exception;
bool Controller::add_movie_controller(string title, string genre, unsigned int year_of_release, unsigned  int likes, string trailer)
{
	
	this->validator.validate_data(title, genre, year_of_release, likes, trailer);

	vector<Movie> movies = this->repository->get_data_repository();

	for (auto movie : movies)
	{
		if (movie.get_trailer() == trailer)
		{
			throw std::exception();

		}
	}

	Movie new_movie = Movie(title, genre, year_of_release, likes, trailer);

	
	this->repository->add_movie(new_movie);

	UndoBaseClass* undo_operation = new UndoAdd{ this->repository,new_movie };
	this->undo_stack.push_back(undo_operation);

	RedoBaseClass* redo_operation = new RedoAdd{ this->repository,new_movie };

	this->redo_stack.push_back(redo_operation);
	return true;

}

bool Controller::remove_movie_controller(string title)
{
	if (this->repository->is_in_list_repository(title) == false)
	{
		return false;
	}

	Movie replaced_movie = this->find_movie_by_title(title);
	this->repository->remove_movie(title);

	
	UndoBaseClass* undo_operation = new UndoDelete{ this->repository,replaced_movie };
	this->undo_stack.push_back(undo_operation);

	RedoBaseClass* redo_operation = new RedoDelete{ this->repository,replaced_movie };
	this->redo_stack.push_back(redo_operation);

	return true;


}

bool Controller::update_movie_controller(string title, string genre, unsigned int year_of_release, unsigned int likes, string trailer)
{
	if (this->repository->is_in_list_repository(title) == false)
	{
		throw exception();
	}
	this->validator.validate_data(title, genre, year_of_release, likes, trailer);

	Movie modified_movie = this->find_movie_by_title(title);
	Movie movie_replacement = Movie(title, genre, year_of_release, likes, trailer);

	this->repository->update_movie(movie_replacement);



	UndoBaseClass* undo_operation = new UndoUpdate{ this->repository,modified_movie };
	this->undo_stack.push_back(undo_operation);

	RedoBaseClass* redo_operation = new RedoUpdate{ this->repository,modified_movie };
	this->redo_stack.push_back(redo_operation);

	return true;
}

bool Controller::add_movie_watchlist(string title, string genre, unsigned int year_of_release, unsigned int likes, string trailer)
{
	this->validator.validate_data(title, genre, year_of_release, likes, trailer);


	vector<Movie> movies = this->watchlist->get_data_repository();

	for (auto movie : movies)
	{
		if (movie.get_trailer() == trailer)
		{
			throw std::exception();

		}
	}


	Movie new_movie = Movie(title, genre, year_of_release, likes, trailer);

	this->watchlist->add_movie(new_movie);

	return true;
}

int Controller::get_length_of_data()
{
	return this->repository->get_lenght_repository();
}

void Controller::open_watchlist()
{
	this->watchlist->display_watchlist();
	
}

vector<Movie> Controller::get_data_controller()
{
	return this->repository->get_data_repository();

}

vector<Movie> Controller::get_data_watchlist()
{
	return this->watchlist->get_data_repository();

}

void Controller::undo()
{
	if (this->undo_stack.size() == 0)
	{
		throw std::exception();
	}

	this->undo_stack[this->undo_stack.size() - 1]->execute_undo();
	this->undo_stack.pop_back();
}

void Controller::redo()
{
	if (this->redo_stack.size() == 0)
	{
		throw std::exception();
	}

	this->redo_stack[this->redo_stack.size() - 1]->execute_redo();
	this->redo_stack.pop_back();
}

Movie Controller::find_movie_by_title(string title)
{
	vector<Movie> movies = this->get_data_controller();

	for (auto movie : movies)
	{
		if (movie.get_title() == title)
		{
			return movie;
		}
	}
}

#pragma once
#include "Repository.h"
#include <fstream>
using std::ifstream;
using std::ofstream;

class HTML_Repository :public Repository
{
private:
	string file_location;
	Validator validator;
public:

	HTML_Repository(string file_location) :file_location(file_location) {};

	vector<Movie> read_from_file();

	void write_to_file(vector<Movie> movie_list);

	bool add_movie(Movie movie) override;

	bool remove_movie(string title) override;

	bool update_movie(Movie movie) override;

	int get_lenght_repository() override;

	bool is_in_list_repository(string title) override;

	vector<Movie> get_data_repository() override;

	void display_HTML();

};

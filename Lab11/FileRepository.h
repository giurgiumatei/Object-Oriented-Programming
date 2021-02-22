#pragma once
#include "Repository.h"
#include <fstream>
using std::ifstream;
using std::ofstream;

class File_Repository :public Repository
{
private:
	string file_location;

	Validator validator;
public:

	File_Repository(string file_location):file_location(file_location) {};

	vector<Movie> read_from_file();

	void write_to_file(vector<Movie> movie_list);

	bool add_movie(Movie movie) override;

	bool remove_movie(string title) override;

	bool update_movie(Movie movie) override;

	int get_lenght_repository() override;

	bool is_in_list_repository(string title) override;

	vector<Movie> get_data_repository() override;


};

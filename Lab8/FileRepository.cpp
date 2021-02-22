#include "FileRepository.h"


vector<Movie> File_Repository::read_from_file()
{
	ifstream fin(this->file_location);

	Movie new_movie;

	vector<Movie> movie_list;
	
	while (fin >>new_movie)
	{	
		movie_list.push_back(new_movie);
		
	}

	fin.close();

	return movie_list;


}

void File_Repository::write_to_file(vector<Movie> movie_list)
{
	ofstream fout(this->file_location);

	if (!fout.is_open())
	{
		return;
	}

	for (auto movie : movie_list)
	{
		fout << movie;
	}

	fout.close();

}

bool File_Repository::add_movie(Movie movie)
{
	cout << "a ajuns! ";
	vector<Movie> movie_list = this->read_from_file();

	movie_list.push_back(movie);

	this->write_to_file(movie_list);

	return true;

}

bool File_Repository::remove_movie(string title)
{

	vector<Movie> movie_list = this->read_from_file();
	int index = 0;
	for (auto movie : movie_list)
	{
		if (movie.get_title() == title)
		{
			movie_list.erase(movie_list.begin() + index);
			this->write_to_file(movie_list);
			return true;
		}
		index++;
	}


	return false;
}

bool File_Repository::update_movie(Movie movie)
{
	vector<Movie> movie_list = this->read_from_file();
	int index = 0;
	for (auto movie_loop : movie_list)
	{
		if (movie_loop.get_title() == movie.get_title())
		{
			movie_list[index] = movie;
			this->write_to_file(movie_list);
			return true;
		}
	}

	return false;
}

int File_Repository::get_lenght_repository()
{
	vector<Movie> movie_list = this->read_from_file();
	return movie_list.size();
}

bool File_Repository::is_in_list_repository(string title)
{
	vector<Movie> movie_list = this->read_from_file();

	for (auto movie : movie_list)
	{
		if (movie.get_title() == title)
		{

			return true;
		}
	}


	return false;
}

vector<Movie> File_Repository::get_data_repository()
{
	return this->read_from_file();
}

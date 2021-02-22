#include "FileRepository.h"


vector<Movie> File_Repository::read_from_file()
{
	ifstream file_input(this->file_location);

	Movie new_movie;

	vector<Movie> movie_list;

	while (file_input >> new_movie)
	{
		movie_list.push_back(new_movie);

	}

	file_input.close();
	//movie_list.pop_back();

	return movie_list;


}

void File_Repository::write_to_file(vector<Movie> movie_list)
{
	ofstream file_output(this->file_location);



	for (auto movie : movie_list)
	{
		file_output << movie;
	}

	file_output.close();

}

bool File_Repository::add_movie(Movie movie)
{

	vector<Movie> movie_list = this->read_from_file();



	movie_list.push_back(movie);

	this->validator.add_to_trailers(movie.get_trailer());

	this->write_to_file(movie_list);

	return true;

}

bool File_Repository::remove_movie(string title)
{

	vector<Movie> movie_list = this->read_from_file();

	this->validator.remove_from_trailers(title);
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

	this->validator.add_to_trailers(movie.get_trailer());

	for (auto movie_loop : movie_list)
	{
		if (movie_loop.get_title() == movie.get_title())
		{

			this->validator.remove_from_trailers(movie_loop.get_title());
			movie_list[index] = movie;

			this->write_to_file(movie_list);
			return true;
		}
		index++;
	}

	throw std::exception();

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

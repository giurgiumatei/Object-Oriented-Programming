#include "HTMLRepository.h"
#include <Windows.h>
using std::endl;
vector<Movie> HTML_Repository::read_from_file()
{
	ifstream file_input(this->file_location);

	int number_of_useless_lines = 14,position;
	string line,title,genre,trailer,year,number_of_likes;
	unsigned int year_of_release, likes;

	while (number_of_useless_lines != 0)
	{
		number_of_useless_lines -= 1;

		getline(file_input, line);
		

	}

	Movie new_movie;

	vector<Movie> movie_list;

	while (getline(file_input, line))
	{
		if (*(line.begin() + 3) == 'a')
		{
			break;
		}

		getline(file_input, line);
	
		position = line.find(">");
		line.erase(0, position + 1);
		position = line.find("<");
		title = line.substr(0, position);
		

		getline(file_input, line);
	
		position = line.find(">");
		line.erase(0, position + 1);
		position = line.find("<");
		genre = line.substr(0, position);
		

		getline(file_input, line);
		
		position = line.find(">");
		line.erase(0, position + 1);
		position = line.find("<");
		year = line.substr(0, position);
		
		year_of_release= stoul(year);
		
		getline(file_input, line);
		
		position = line.find(">");
		line.erase(0, position + 1);
		position = line.find("<");
		number_of_likes = line.substr(0, position);
		likes= stoul(number_of_likes);

		getline(file_input, line);
		
		position = line.find(">");
		line.erase(0, position + 1);
		position = line.find("<");
		trailer = line.substr(0, position);
		

		new_movie = Movie(title, genre, year_of_release, likes, trailer);


		movie_list.push_back(new_movie);
		getline(file_input, line);

	}

	file_input.close();

	return movie_list;


}

void HTML_Repository::write_to_file(vector<Movie> movie_list)
{
	ofstream file_output(this->file_location);


	file_output << "<!DOCTYPE html>" << endl;
	file_output << "<html>" << endl;
	file_output << "<head>" << endl;
	file_output << "<title>myList</title>" << endl;
	file_output << "</head>" << endl;
	file_output << "<body>" << endl;
	file_output << "<table border = '1'>" << endl;
	file_output << "<tr>" << endl;
	file_output << "<td>Title</td>" << endl;
	file_output << "<td>Genre</td>" << endl;
	file_output << "<td>Year of release</td>" << endl;
	file_output << "<td>Number of likes</td>" << endl;
	file_output << "<td>Trailer</td>" << endl;
	file_output << "</tr>" << endl;
	
		

	for (auto movie : movie_list) {

		file_output << "<tr>" << endl;
		file_output << "<td>" << movie.get_title() << "</td>" << endl;
		file_output << "<td>" << movie.get_genre() << "</td>" << endl;
		file_output << "<td>" << movie.get_year_of_release() << "</td>" << endl;
		file_output << "<td>" << movie.get_likes() << "</td>" << endl;
		file_output << "<td>" << movie.get_trailer() << "</td>" << endl;
		file_output << "</tr>" << endl;
	}

	file_output << "</table>" << endl;
	file_output << "</body>" << endl;
	file_output << "</html>" << endl;



	file_output.close();

}

bool HTML_Repository::add_movie(Movie movie)
{

	vector<Movie> movie_list = this->read_from_file();

	

	movie_list.push_back(movie);

	this->write_to_file(movie_list);

	return true;

}

bool HTML_Repository::remove_movie(string title)
{

	vector<Movie> movie_list = this->read_from_file();
	int index = 0;
	this->validator.remove_from_trailers(title);
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

bool HTML_Repository::update_movie(Movie movie)
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
	}

	return false;
}

int HTML_Repository::get_lenght_repository()
{
	vector<Movie> movie_list = this->read_from_file();
	return movie_list.size();
}

bool HTML_Repository::is_in_list_repository(string title)
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

vector<Movie> HTML_Repository::get_data_repository()
{
	return this->read_from_file();
}

void HTML_Repository::display_watchlist()
{
	string path = "\"" + this->file_location + "\"";
	ShellExecuteA(NULL, "open", "C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe", path.c_str(), NULL, SW_SHOWMAXIMIZED);
	
}


//this function opens the html file with the data, comment out before submitting

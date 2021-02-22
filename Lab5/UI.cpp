#pragma once
#include "UI.h"

void UI::print_menu_start()
{
	cout << "Enter A for Administrator mode or B for User mode: \n";

}

void UI::menu_for_which_mode()
{
	string option;
	while (1 == 1)
	{
		this->print_menu_start();
		getline(cin, option);

		if (option == "mode A")
		{
			this->administrator_mode();
			break;
		}
		else if (option == "mode B")
		{
			this->user_mode();
			break;
		}
		else
		{
			cout << "Invalid command! \n";
		}

	}


}

void UI::print_menu_administrator()
{
	cout << "1.Add a movie: \n";
	cout << "2.Delete a movie: \n";
	cout << "3.Update a movie: \n";
	cout << "4.See the list of movies: \n";
	cout << "5.Exit program. \n";

}

void UI::print_menu_user()
{
	cout << "1.See the list of movies: \n";
	cout << "2.Exit program. \n";
}

void UI::administrator_mode()
{
	string command_line;
	while (1 == 1)
	{
		this->print_menu_administrator();
		getline(cin, command_line);
		string command = command_line.substr(0, command_line.find(" "));
		int position = command_line.find(" ");
		command_line.erase(0, position + 1);

		if (command == "exit")
		{
			break;
		}

		else if (command == "add")
		{
			this->add_movie_ui(command_line);
		}
		else if (command == "delete")
		{
			this->remove_movie_ui(command_line);
		}

		else if (command == "update")
		{
			this->update_movie_ui(command_line);
		}

		else if (command == "list")
		{
			this->list_movies();
		}
		else
		{
			cout << "Invalid command!\n";
		}



	}


}

void UI::user_mode()
{
	string command_line;
	while (1 == 1)
	{
		this->print_menu_user();
		getline(cin, command_line);
		string command = command_line.substr(0, command_line.find(" "));
		int position = command_line.find(" ");
		command_line.erase(0, position + 1);

		if (command == "exit")
		{
			break;
		}


		else if (command == "list")
		{

		}
		else
		{
			cout << "Invalid command!\n";
		}



	}


}

void UI::add_movie_ui(string command_line)
{
	
	int position = command_line.find(", ");
	string title = command_line.substr(0, position);
	command_line.erase(0, position + 2);
	position = command_line.find(", ");
	string genre = command_line.substr(0, position);
	command_line.erase(0, position + 2);
	position = command_line.find(", ");
	string year = command_line.substr(0, position);
	unsigned int year_of_release = stoul(year);
	command_line.erase(0, position + 2);
	position = command_line.find(", ");
	string number_of_likes = command_line.substr(0, position);
	unsigned int likes = stoul(number_of_likes);
	command_line.erase(0, position + 2);
	string trailer = command_line;
	this->controller.add_movie_controller(title, genre, year_of_release, likes, trailer);



}

void UI::remove_movie_ui(string command_line)
{
	
	int position = command_line.find(", ");
	string title = command_line.substr(0, position);
	if (this->controller.remove_movie_controller(title) == false)
	{
		cout << "That movie is not currently in the list! \n";
	}
}

void UI::update_movie_ui(string command_line)
{
	int position = command_line.find(", ");
	string title = command_line.substr(0, position);
	command_line.erase(0, position + 2);
	position = command_line.find(", ");
	string genre = command_line.substr(0, position);
	command_line.erase(0, position + 2);
	position = command_line.find(", ");
	string year = command_line.substr(0, position);
	unsigned int year_of_release = stoul(year);
	command_line.erase(0, position + 2);
	position = command_line.find(", ");
	string number_of_likes = command_line.substr(0, position);
	unsigned int likes = stoul(number_of_likes);
	command_line.erase(0, position + 2);
	string trailer = command_line;
	
	if (this->controller.update_movie_controller(title, genre, year_of_release, likes, trailer) == false)
	{
		cout << "That movie is not currently in the list! \n";
	}

}

void UI::list_movies()
{
	
	DynamicVector<Movie> vector_of_movies = this->controller.get_data_controller();
	Movie* movies = vector_of_movies.get_elements_data();

	for (int i = 0; i <vector_of_movies.get_lenght(); i++)
	{
		cout << movies[i].get_title() << ", ";
		cout << movies[i].get_genre() << ", ";
		cout << movies[i].get_year_of_release() << ", ";
		cout << movies[i].get_likes() << ", ";
		cout << movies[i].get_trailer()<<"\n";
	}


}

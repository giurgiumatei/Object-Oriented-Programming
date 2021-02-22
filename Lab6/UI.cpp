#pragma once
#include "UI.h"

void UI::print_menu_start()
{
	cout << "Enter moda A for Administrator mode or mode B for User mode: \n";

}

void UI::menu_for_which_mode()
{
	string option;
	while (true)
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
		else if (option == "exit")
		{
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
	cout <<"\n"<< "1.Add a movie: \n";
	cout << "2.Delete a movie: \n";
	cout << "3.Update a movie: \n";
	cout << "4.See the list of movies: \n";
	cout << "5.Exit program. \n";

}

void UI::show_movie_to_user(int index)
{
	DynamicVector<Movie> vector_of_movies = this->controller.get_data_controller();
	Movie* movies = vector_of_movies.get_elements_data();

	cout << movies[index].get_title() << ", ";
	cout << movies[index].get_genre() << ", ";
	cout << movies[index].get_year_of_release() << ", ";
	cout << movies[index].get_likes() << ", ";
	cout << movies[index].get_trailer() << "\n";


}

void UI::administrator_mode()
{
	string command_line;
	while (true)
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

		else if (command == "mode")
		{
			if (command_line == "B")

			{
				this->user_mode();
				break;
			}
			else
			{
				cout << "Invalid command!\n";
			}
		}
		else
		{
			cout << "Invalid command!\n";
		}



	}


}

void UI::user_mode()
{
	int index = 0;
	bool showmovie = true;
	string command_line;
	while (true)
	{
		if (showmovie == true)
		{
			this->show_movie_to_user(index);
		}
		else
		{
			showmovie = true;
		}
		getline(cin, command_line);
		string command = command_line.substr(0, command_line.find(" "));
		int position = command_line.find(" ");
		command_line.erase(0, position + 1);

		if (command == "exit")
		{
			break;
		}

		else if (command == "mylist")
		{
			this->see_watchlist();
		}
		else if (command == "list")
		{
			showmovie = false;
			string empty_string = " ";

			if (command_line.find(", ") != string::npos)
			{
				string genre = command_line.substr(0, command_line.find(", "));
				int position = command_line.find(", ");
				command_line.erase(0, position + 2);
				string likes = command_line;
				unsigned int likes_as_integers = stoul(likes);
				list_by_genre_and_likes(genre, likes_as_integers);

			}
			else if (command_line.find(" ") != string::npos)
			{	
				string genre = command_line;

				list_by_genre(genre);

			}
			else
			{
				
				this->list_by_genre(empty_string);
			}
		}
		else if (command == "save")
		{
			this->save_movie(command_line);
		}
		else if (command == "next")
		{
			index++;
			if (index == this->controller.get_length_of_data())
			{
				index=0;
			}
		}
		else if (command == "mode")
		{
			if (command_line == "A")

			{
				this->administrator_mode();
				break;
			}
			else
			{
				cout << "Invalid command!\n";
			}
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

void UI::list_by_genre(string genre)
{ 
	DynamicVector<Movie> vector_of_movies = this->controller.get_data_controller();
	Movie* movies = vector_of_movies.get_elements_data();
	string command_line;
	string command;
	int position;
	bool exit_loop = false;

	for (int i = 0; i < vector_of_movies.get_lenght(); i++)
	{
		if (movies[i].get_genre() == genre || genre ==" ")
		{
			cout << movies[i].get_title() << ", ";
			cout << movies[i].get_genre() << ", ";
			cout << movies[i].get_year_of_release() << ", ";
			cout << movies[i].get_likes() << ", ";
			cout << movies[i].get_trailer() << "\n";

			getline(cin, command_line);
			command = command_line.substr(0, command_line.find(" "));
			position = command_line.find(" ");
			command_line.erase(0, position + 1);

			while (true)
			{
				if (command == "next")
				{
					break;
				}
				else if (command == "save")
				{
					this->controller.add_movie_watchlist(movies[i].get_title(), movies[i].get_genre(), movies[i].get_year_of_release(), movies[i].get_likes(), movies[i].get_trailer());
					break;
				}

				else if (command == "exit")
				{
					exit_loop = true;
					break;
				}
				else
				{
					cout << "Invalid command!\n ";
				}


			}

			if (exit_loop == true)
			{
				break;
			}

			if (i == vector_of_movies.get_lenght() - 1)
			{
				i = -1;
			}


		}
	}

	


}

void UI::list_by_genre_and_likes(string genre,unsigned int likes)
{ 
	DynamicVector<Movie> vector_of_movies = this->controller.get_data_controller();
	Movie* movies = vector_of_movies.get_elements_data();
	string command_line;
	string command;
	int position;

	for (int i = 0; i < vector_of_movies.get_lenght(); i++)
	{
		if (movies[i].get_genre() == genre && movies[i].get_likes()>=likes)
		{
			cout << movies[i].get_title() << ", ";
			cout << movies[i].get_genre() << ", ";
			cout << movies[i].get_year_of_release() << ", ";
			cout << movies[i].get_likes() << ", ";
			cout << movies[i].get_trailer() << "\n";

			

		}

	}


}

void UI::see_watchlist()
{
	DynamicVector<Movie> vector_of_movies = this->controller.get_data_watchlist();
	Movie* movies = vector_of_movies.get_elements_data();

	for (int i = 0; i < vector_of_movies.get_lenght(); i++)
	{
		cout << movies[i].get_title() << ", ";
		cout << movies[i].get_genre() << ", ";
		cout << movies[i].get_year_of_release() << ", ";
		cout << movies[i].get_likes() << ", ";
		cout << movies[i].get_trailer() << "\n";
	}
}

string UI::save_movie(string title)
{
	DynamicVector<Movie> vector_of_movies = this->controller.get_data_controller();
	Movie* movies = vector_of_movies.get_elements_data();

	for (int i = 0; i < vector_of_movies.get_lenght(); i++)
	{
		this->controller.add_movie_watchlist(movies[i].get_title(), movies[i].get_genre(), movies[i].get_year_of_release(), movies[i].get_likes(), movies[i].get_trailer());
		break;
	}

	return title;
}

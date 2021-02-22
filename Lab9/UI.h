#pragma once
#include "Controller.h"
#include <iostream>
using std::stoul;
using std::cin;
using std::cout;
using std::getline;


class Start_UI
{

public:
	Start_UI() {};

	string Start1();

	string Start2();
};


class UI
{
private:

	Controller controller;

public:

	UI(Controller controller) : controller(controller) {};

	void print_menu_start();
	void menu_for_which_mode();
	void print_menu_administrator();
	void show_movie_to_user(int index);
	void administrator_mode();
	void user_mode();
	void add_movie_ui(string command_line);
	void remove_movie_ui(string command_line);
	void update_movie_ui(string command_line);
	void list_movies();
	void list_by_genre(string genre);
	void list_by_genre_and_likes(string genre, unsigned int likes);
	void see_watchlist();
	string save_movie(string title);


};
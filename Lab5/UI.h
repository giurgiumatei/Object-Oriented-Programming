#pragma once
#include "Controller.h"
#include <iostream>
using std::stoul;
using std::cin;
using std::cout;
using std::getline;





class UI
{
private:

	Controller controller;

public:

	UI(Controller controller) : controller(controller) {};

	void print_menu_start();
	void menu_for_which_mode();
	void print_menu_administrator();
	void print_menu_user();
	void administrator_mode();
	void user_mode();
	void add_movie_ui(string command_line);
	void remove_movie_ui(string command_line);
	void update_movie_ui(string command_line);
	void list_movies();


};
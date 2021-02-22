#pragma once
#include <qwidget.h>
#include "Controller.h"
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>
class GUI :
	public QWidget
{
private:
	Controller& controller;

public:

	GUI(Controller& controller);

	//graphical elements
	QListWidget* movies_list_widget;
	QLineEdit* genre_line_edit;
	QLineEdit* title_line_edit;
	QLineEdit* trailer_line_edit;
	QLineEdit* likes_line_edit;
	QLineEdit* year_line_edit;
	QPushButton* add_button;
	QPushButton* delete_button;
	QPushButton* update_button;





private:

	void initialise_GUI();
	void populate_list();
	void connect_signals_and_slots();

	int get_selected_index();
	
	void add_movie();
	void delete_movie();
	void update_movie();




};


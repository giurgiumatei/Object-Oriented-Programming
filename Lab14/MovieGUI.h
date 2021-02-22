#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MovieGUI.h"
#include "Controller.h"
#include "MyListWidget.h"
class MovieGUI : public QMainWindow
{
    Q_OBJECT

public:
    MovieGUI(Controller& controller, MyListWidget& mylist_widget, QWidget* parent = Q_NULLPTR);

private:

	Controller& controller;

	MyListWidget& mylist_widget;

	Ui::MovieGUIClass ui;

	int index_of_current;
	string mode = "A";

	void connect_signals_and_slots();

	void populate_list();
	void populate_mylist();
	void current();
	int get_selected_index();

	void mode_line_edit();
	void delete_movie();

	
public slots:

	void add_movie();
	void update_movie();
	void select_movie();
	void open_watchlist();
	void next();
	void save();
	void list_by_filter();
	void change_selection_mode();
	void undo();
	void redo();
	void open_watchlist_in_new_window();


};

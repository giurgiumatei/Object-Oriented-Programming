#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ShoppingList.h"
#include "Controller.h"
class ShoppingList : public QMainWindow
{
	Q_OBJECT

public:
	ShoppingList(Controller& controller,QWidget *parent = Q_NULLPTR);

private:
	Controller& controller;
	Ui::ShoppingListClass ui;
	int get_selected_index();
	void populate_list();
	int index_of_current;

public slots:
	void add();
	void remove();
	void filter();
	void select_item();

};

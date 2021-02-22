#pragma once

#include <QWidget>
#include "ui_MyListWidget.h"
#include "MyListTableModel.h"

class MyListWidget : public QWidget
{
	Q_OBJECT

public:
	MyListWidget(MyListTableModel* model, QWidget* parent = Q_NULLPTR);
	~MyListWidget() {};

	void add_in_MyList(const string& title);
private:
	Ui::MyListWidget ui;
	MyListTableModel* model;
};

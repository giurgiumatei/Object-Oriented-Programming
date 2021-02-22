#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MovieGUI.h"

class MovieGUI : public QMainWindow
{
	Q_OBJECT

public:
	MovieGUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::MovieGUIClass ui;
};

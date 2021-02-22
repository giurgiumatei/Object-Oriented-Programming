#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MovieGUIChart.h"

class MovieGUIChart : public QMainWindow
{
	Q_OBJECT

public:
	MovieGUIChart(QWidget *parent = Q_NULLPTR);

private:
	Ui::MovieGUIChartClass ui;
};

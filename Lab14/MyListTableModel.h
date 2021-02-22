#pragma once
#include "qabstractitemmodel.h"
#include "Controller.h"

class MyListTableModel :public QAbstractTableModel
{

private:
	Controller& controller;

public:
	MyListTableModel(Controller& controller) :controller{ controller } {};
	void add_in_MyList(string title);
	bool insertRows(int position, int rows, const QModelIndex& index = QModelIndex()) override;
	bool removeRows(int position, int rows, const QModelIndex& index = QModelIndex()) override;
	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	int columnCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	QVariant header_data(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;


};


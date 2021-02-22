#pragma once
#include "Service.h"
#include <qabstractitemmodel.h>
class Model :
	public QAbstractTableModel
{
private:
	Service& service;
public:
	Model(Service& service);
	int columnCount(const QModelIndex& parent = QModelIndex()) const;
	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	Qt::ItemFlags flags(const QModelIndex& index) const override;
	bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

	void addIdea(string description, string creator, string act);
	void acceptIdea(QModelIndex index);
	void savePlot();
	~Model();
};
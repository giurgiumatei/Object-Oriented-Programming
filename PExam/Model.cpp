#include "Model.h"

int Model::rowCount(const QModelIndex& parent) const
{

	return service.get_stars().size() + 1;
}

int Model::columnCount(const QModelIndex& parent) const
{
	return 5;
}

QVariant Model::data(const QModelIndex& index, int role) const
{
	int line = index.row();
	int column = index.column();

	if (line == rowCount() - 1)
	{
		return QVariant();
	}

	Star star = this->service.get_stars().at(line);

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		if (column == 0)
		{
			return QString::fromStdString(star.getName());
		}
		else if (column == 1)
		{
			return QString::fromStdString(star.getConstelation());
		}

		else if (column == 2)
		{
			return QString::fromStdString(to_string(star.getRa()));
		}

		else if (column == 3)
		{
			return QString::fromStdString(to_string(star.getDec()));
		}
		else if (column == 4)
		{
			return QString::fromStdString(to_string(star.getDiameter()));
		}


	}

	return QVariant();
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
		switch (section)
		{
		case 0:
			return QString::fromStdString("Name");
		case 1:
			return QString::fromStdString("Constellation");
		case 2:
			return QString::fromStdString("RA");
		case 3:
			return QString::fromStdString("Dec");
		case 4:
			return QString::fromStdString("Diameter");
		default:
			break;
		}
	}
	return QVariant();
}

void Model::insert_row()
{
	beginInsertRows(QModelIndex(), this->service.get_stars().size(), this->service.get_stars().size());
	endInsertRows();
}

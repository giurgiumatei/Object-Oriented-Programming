#include "Model.h"

int Model::rowCount(const QModelIndex& parent) const
{

	return service.get_ideas().size()+1;
}

int Model::columnCount(const QModelIndex& parent) const
{
	return 4;
}

QVariant Model::data(const QModelIndex& index, int role) const
{
	int line = index.row();
	int column = index.column();

	if (line == rowCount()-1)
	{
		return QVariant();
	}

	Idea idea=this->service.get_ideas().at(line);

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		if (column == 0)
		{
			return QString::fromStdString(idea.getDescription());
		}
		else if (column == 1)
		{
			return QString::fromStdString(idea.getStatus());
		}

		else if (column == 2)
		{
			return QString::fromStdString(idea.getCreator());
		}

		else if (column == 3)
		{
			return QString::fromStdString(to_string(idea.getAct()));
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
			return QString::fromStdString("Description");
		case 1:
			return QString::fromStdString("Status");
		case 2:
			return QString::fromStdString("Screenwriter");
		case 3:
			return QString::fromStdString("Act");
		default:
			break;
		}
	}
	return QVariant();
}

void Model::insert_row()
{
	beginInsertRows(QModelIndex(), this->service.get_ideas().size(), this->service.get_ideas().size());
	endInsertRows();
}

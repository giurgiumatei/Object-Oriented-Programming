#include "MyListGUI.h"

int MyListGUI::rowCount(const QModelIndex& parent) const
{
	return this->repository.get_lenght_repository();
}

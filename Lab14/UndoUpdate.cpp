#include "UndoUpdate.h"

void UndoUpdate::execute_undo()
{
	this->repository->update_movie(movie);
}

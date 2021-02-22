#include "RedoUpdate.h"

void RedoUpdate::execute_redo()
{
	this->repository->update_movie(movie);
}

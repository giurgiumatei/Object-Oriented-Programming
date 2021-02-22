#include "UndoDelete.h"

void UndoDelete::execute_undo()
{
	this->repository->add_movie(movie);
}

#include "UndoAdd.h"

void UndoAdd::execute_undo()
{
	this->repository->remove_movie(movie.get_title());
}

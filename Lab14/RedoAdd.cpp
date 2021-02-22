#include "RedoAdd.h"

void RedoAdd::execute_redo()
{
	this->repository->add_movie(movie);
}

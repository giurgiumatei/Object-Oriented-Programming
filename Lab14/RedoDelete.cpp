#include "RedoDelete.h"

void RedoDelete::execute_redo()
{
	this->repository->remove_movie(movie.get_title());
}

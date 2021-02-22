#pragma once
#include "UndoBase.h"
#include "Repository.h"


class UndoDelete :public UndoBaseClass
{

private:
	Repository* repository;
	Movie movie;
public:

	UndoDelete(Repository* repository, Movie movie) :repository{ repository }, movie{ movie }, UndoBaseClass() {};
	void execute_undo()override;

};


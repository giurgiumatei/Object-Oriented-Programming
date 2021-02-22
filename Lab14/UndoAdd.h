#pragma once
#include "UndoBase.h"
#include "Repository.h"


class UndoAdd :public UndoBaseClass
{
private:
	Repository* repository;
	Movie movie;
public:

	UndoAdd(Repository* repository, Movie movie) :repository{ repository }, movie{ movie }, UndoBaseClass() {};
	void execute_undo()override;
};


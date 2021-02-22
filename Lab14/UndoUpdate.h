#pragma once
#include "UndoBase.h"
#include "Repository.h"
#include "Domain.h"
class UndoUpdate :public UndoBaseClass
{

private:
	Repository* repository;
	Movie movie;
public:

	UndoUpdate(Repository* repository, Movie movie) :repository{ repository }, movie{ movie }, UndoBaseClass() {};
	void execute_undo()override;

};


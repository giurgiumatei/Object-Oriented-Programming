#pragma once
#include "RedoBase.h"
#include "Repository.h"
#include "Domain.h"

class RedoAdd :public RedoBaseClass
{
private:
	Repository* repository;
	Movie movie;
public:

	RedoAdd(Repository* repository, Movie movie) :repository{ repository }, movie{ movie }, RedoBaseClass() {};
	void execute_redo()override;


};


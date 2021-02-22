#pragma once
#include "RedoBase.h"
#include "Repository.h"
#include "Domain.h"

class RedoDelete :public RedoBaseClass
{
private:
	Repository* repository;
	Movie movie;
public:

	RedoDelete(Repository* repository, Movie movie) :repository{ repository }, movie{ movie }, RedoBaseClass() {};
	void execute_redo()override;


};


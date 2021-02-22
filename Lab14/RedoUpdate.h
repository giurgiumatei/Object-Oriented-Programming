#pragma once
#include "RedoBase.h"
#include "Repository.h"
#include "Domain.h"

class RedoUpdate :public RedoBaseClass
{
private:
	Repository* repository;
	Movie movie;
public:

	RedoUpdate(Repository* repository, Movie movie) :repository{ repository }, movie{ movie }, RedoBaseClass() {};
	void execute_redo()override;


};


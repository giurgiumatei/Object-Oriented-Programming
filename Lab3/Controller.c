#include "Controller.h"



Controller* createController(Repository* repository)
{
	Controller* controller = (Controller*)malloc(sizeof(Controller));
	controller->repository = repository;

	return controller;


}

int addProductController(Controller* controller, int id, char* supplier, char* name, int quantity)
{

	Material material = createMaterial(id, supplier, name, quantity);

	if (hasMaterialbyID(controller->repository, id) == 1)
	{
		return 0;
	}

	else
	{


		addMaterial(controller->repository, material);
		return 1;

	}


}

int removeProductController(Controller* controller, int id)
{

	if (hasMaterialbyID(controller->repository, id) == 0)
	{
		return 0;
	}

	else
	{
		removeMaterial(controller->repository, id);

		return 1;

	}


}

int updateProductController(Controller* controller, int id, char* supplier, char* name, int quantity)
{
	Material material = createMaterial(id, supplier, name, quantity);

	if (hasMaterialbyID(controller->repository, id) == 0)
	{
		return 0;
	}

	else
	{
		updateMaterial(controller->repository, material);
		return 1;

	}



}


Repository* getListController(Controller* controller)
{

	return controller->repository;
}





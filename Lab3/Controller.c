#include "Controller.h"



Controller* createController(Repository* repository,OperationsStack* stack)
{
	Controller* controller = (Controller*)malloc(sizeof(Controller));

	controller->repository = repository;
	controller->stack = stack;

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
		
		Material* material_for_undo;
		material_for_undo = (Material*)malloc(sizeof(Material));
		*material_for_undo = material;
		
		Operation* operation = createOperation(material_for_undo,"add");

		addtoStack(controller->stack, operation);

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
		Material material_removed=removeMaterial(controller->repository, id);

		Material* material_for_undo;
		material_for_undo = (Material*)malloc(sizeof(Material));
		*material_for_undo = material_removed;

		Operation* operation = createOperation(material_for_undo, "remove");

		addtoStack(controller->stack, operation);

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
		

		Material material_updated = updateMaterial(controller->repository, material);

		Material* material_for_undo;
		material_for_undo = (Material*)malloc(sizeof(Material));
		*material_for_undo = material_updated;

		Operation* operation = createOperation(material_for_undo, "update");
		
		addtoStack(controller->stack, operation);

		return 1;

	}



}


int getLenghtController(Controller* controller)
{
	int lenght;
	lenght = getLenght(controller->repository);
	return lenght;

}


Material* getMaterialsDataController(Controller* controller)
{

	
	return getMaterialsData(controller->repository);


}


bool undoControllerFunction(Controller* controller)
{
	if (undo(controller->stack) == false)
	{
		return false;
	}

	return true;

}
 

bool redoControllerFunction(Controller* controller)
{
	if (redo(controller->stack) == false)
	{
		return false;
	}

	return true;

}

Material* sortListAlphabetically(Controller* controller, Material* materials)
{
	Material auxiliary_material;

	for (int i = 0; i < getLenghtController(controller); i++)
	{
		for (int j = i + 1; j < getLenghtController(controller) - 1; j++)
		{
			if (strcmp(getSupplier(&materials[i]), getSupplier(&materials[j])) > 0)
			{
				auxiliary_material = materials[i];
				materials[i] = materials[j];
				materials[j] = auxiliary_material;


			}

		}

	}

	return materials;


}
#pragma once
#include "Repository.h"
#include "Undo Controller.h"

typedef struct {

	Repository* repository;
	OperationsStack* stack;


}Controller;


Controller* createController(Repository* repository,OperationsStack* stack);

int addProductController(Controller* controller, int id, char* supplier, char* name, int quantity);

int removeProductController(Controller* controller, int id);

int updateProductController(Controller* controller, int id, char* supplier, char* name, int quantity);

Repository* getListController(Controller* controller);

int getLenghtController(Controller* controller);



Material* getMaterialsDataController(Controller* controller);

bool undoControllerFunction(Controller* controller);

bool redoControllerFunction(Controller* controller);

Material* sortListAlphabetically(Controller* controller, Material* materials);
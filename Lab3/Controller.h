#pragma once
#include "Repository.h"
typedef struct {

	Repository* repository;


}Controller;


Controller* createController(Repository* repository);

int addProductController(Controller* controller, int id, char* supplier, char* name, int quantity);

int removeProductController(Controller* controller, int id);

int updateProductController(Controller* controller, int id, char* supplier, char* name, int quantity);

Repository* getListController(Controller* controller);
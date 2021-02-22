#pragma once
#include "Domain.h"
#define MAX_SIZE 128
#include "Repository.h"
#include <stdbool.h>
typedef struct
{
	Material* material;
	char* operation_type;
} Operation;


Operation* createOperation(Material* material, char* operation_type);
void destroyOperation(Operation* operation);
Operation* copyOperation(Operation* operation);


char* getOperationType(Operation* operation);
Material* getMaterial(Operation* operation);

// ---------------------------------------------------------------
typedef struct
{
	Repository* repository;
	Operation* operations;
	int length,index;
} OperationsStack;


OperationsStack* createStack();

void destroyStack(OperationsStack* s);

void destroyOperation(Operation* operation);

Operation* copyOperation(Operation* operation);

char* getOperationType(Operation* operation);

Material* getMaterial(Operation* operation);

OperationsStack* createStack(Repository* repository);

void destroyStack(OperationsStack* stack);

void addtoStack(OperationsStack* stack, Operation* operation);

void undoFunction(OperationsStack* stack, Operation* operation);

void redoFunction(OperationsStack* stack, Operation* operation);

bool undo(OperationsStack* stack);

bool redo(OperationsStack* stack);
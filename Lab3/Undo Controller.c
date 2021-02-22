#define _CRT_SECURE_NO_WARNINGS
#include "Undo Controller.h"
#include <string.h>
#include <stdlib.h>


Operation* createOperation(Material* material, char* operationType)
{
	Operation* operation = (Operation*)malloc(sizeof(Operation));
	operation->material = material;

	
	operation->operation_type = (char*)malloc(sizeof(char) * 100);
	strcpy(operation->operation_type, operationType);
	
	
		

	return operation;
}

void destroyOperation(Operation* operation)
{
	if (operation == NULL)
		return;

	

	free_material_memory_leaks(*(operation->material));

	free(operation->operation_type);
	
	free(operation);
}

Operation* copyOperation(Operation* operation)
{
	if (operation == NULL)
		return NULL;

	Operation* new_operation = createOperation(operation->material, operation->operation_type);
	return new_operation;
}

char* getOperationType(Operation* operation)
{

	return operation->operation_type;

}



Material* getMaterial(Operation* operation)
{

	return operation->material;

}

OperationsStack* createStack(Repository* repository)
{
	OperationsStack* stack = (OperationsStack*)malloc(sizeof(OperationsStack));
	stack->length = 0;
	stack->index = 0;
	stack->operations = (Operation*)malloc(sizeof(Operation));
	stack->repository = repository;
	return stack;


}

void destroyStack(OperationsStack* stack)
{
	if(stack==NULL)
	{
		return;
	}

	for (int i = 0; i < stack->length; i++)
	{
		destroyOperation(&(stack->operations[i]));

	}

	free(stack);


}

void addtoStack(OperationsStack* stack, Operation* operation)
{


	stack->operations[stack->index] = *operation;

	
	
	if (stack->length == stack->index)
	{
		stack->length += 1;
		stack->operations = (Operation*)realloc(stack->operations, (stack->length + 1) * sizeof(Operation));
	}

	
	
	stack->index += 1;

	
}

void undoFunction(OperationsStack* stack, Operation* operation)
{
	
	if (strcmp(operation->operation_type, "add")==0)
	{
		
		removeMaterial(stack->repository, operation->material->id);

	}

	else if(strcmp(operation->operation_type,"remove")==0)
	{
		addMaterial(stack->repository, *operation->material);
	}

	else if (strcmp(operation->operation_type, "update")==0)
	{

		Material material_updated = updateMaterial(stack->repository, *operation->material);

		Material* material_for_undo;
		material_for_undo = (Material*)malloc(sizeof(Material));
		*material_for_undo = material_updated;
		
		Operation* operation = createOperation(material_for_undo, "update");
		addtoStack(stack, operation);
		
		stack->index -= 1;

	}



}

void redoFunction(OperationsStack* stack, Operation* operation)
{

	if (strcmp(operation->operation_type, "add")==0)
	{

		addMaterial(stack->repository, *operation->material);

	}

	else if (strcmp(operation->operation_type, "remove")==0)
	{
		removeMaterial(stack->repository, operation->material->id);
	}

	else if (strcmp(operation->operation_type, "update")==0)
	{

		Material material_updated = updateMaterial(stack->repository, *operation->material);

		Material* material_for_undo;
		material_for_undo = (Material*)malloc(sizeof(Material));
		*material_for_undo = material_updated;
		
		Operation* operation = createOperation(material_for_undo, "update");
		addtoStack(stack, operation);

		stack->index -= 1;
	

	}
}




bool undo(OperationsStack* stack)
{

	if (stack->index == 0)
	{
		
		return false;

	}
	
	stack->index -= 1;
	
	Operation* operation = createOperation(stack->operations[stack->index].material, stack->operations[stack->index].operation_type);


	undoFunction(stack, operation);

	
	
	return true;

}

bool redo(OperationsStack* stack)
{
	if (stack->index ==stack->length)
	{

		return false;

	}

	

	Operation* operation = createOperation(stack->operations[stack->index ].material, stack->operations[stack->index ].operation_type);

	redoFunction(stack, operation);
	stack->index += 1;
	
	printf("%d\n", stack->index);
	return true;

}




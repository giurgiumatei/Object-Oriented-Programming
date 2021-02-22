#pragma once
#include "Tests.h"


void test_for_add_function_added_to_list(Controller* controller, OperationsStack* stack,Repository* repository)
{
	char* supplier = "supplier";

	char* name = "name";

	assert(addProductController(controller, 123, supplier, name, 1) == 1);

	assert(repository->lenght == 1);

	assert(stack->length == 1);

	assert(stack->index == 1);


}
void test_for_remove_function_removed_from_list(Controller* controller, OperationsStack* stack, Repository* repository)
{
	assert(removeProductController(controller, 123) == 1);

	assert(repository->lenght == 0);

	assert(stack->length == 0);

	assert(stack->index == 0);



}

void test_for_update_function_updates_element_quantityistwo(Controller* controller, OperationsStack* stack, Repository* repository)
{
	char* supplier = "supplier";

	char* name = "name";

	assert(addProductController(controller, 123, supplier, name, 1) == 1);

	char* new_name = "new_name";

	char* new_supplier = "new_supplier";

	assert(updateProductController(controller, 123, new_supplier, new_name, 2) == 1);

	assert(repository->materials[repository->lenght].quantity == 2);


}

void test_for_undo_function_returns_true(Controller* controller, OperationsStack* stack, Repository* repository)
{

	assert(undo(stack) == true);


}

void test_for_redo_function_returns_true(Controller* controller, OperationsStack* stack, Repository* repository)
{

	assert(redo(stack) == true);


}




void test_Main_Function_calls_test_functions()
{
	Repository* repository = createRepository();

	OperationsStack* stack = createStack(repository);
	
	Controller* controller = createController(stack->repository, stack);

	assert(repository->lenght == 0);
	
	assert(stack->length == 0);

	assert (stack->index == 0);

	
	test_for_add_function(controller, stack, repository);

	test_for_remove_function(controller, stack, repository);

	test_for_update_function(controller, stack, repository);

	test_for_undo_function(controller, stack, repository);

	test_for_redo_function(controller, stack, repository);
	

	free(stack);
	free(repository);
	free(controller);


}
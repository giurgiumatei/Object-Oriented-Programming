#pragma once
#include <assert.h>
#include "Undo Controller.h"
#include "Controller.h"
#include "Domain.h"

void test_Main_Function();

void test_for_add_function(Controller* controller, OperationsStack* stack, Repository* repository);

void test_for_remove_function(Controller* controller, OperationsStack* stack, Repository* repository);

void test_for_update_function(Controller* controller, OperationsStack* stack, Repository* repository);

void test_for_undo_function(Controller* controller, OperationsStack* stack, Repository* repository);

void test_for_redo_function(Controller* controller, OperationsStack* stack, Repository* repository);
#define _CRTDBG_MAP_ALLOC
#include "UI.h"
#include <stdlib.h>
#include <crtdbg.h>
#include "Undo Controller.h"

int main()
{
	//testsProductRepo();
	//testController();

	Repository* repository = createRepository();

	OperationsStack* stack = createStack(repository);

	Controller* controller = createController(stack->repository,stack);

	


	UI* ui = createUI(controller);
	//destroyUI(ui);
	//destroyController(ctrl);
	startUI(ui);
	free(repository);
	free(controller);
	free(ui);

	_CrtDumpMemoryLeaks();

	return 0;
}
#include "UI.h"



int main()
{
	//testsProductRepo();
	//testController();

	Repository* repository = createRepository();


	Controller* controller = createController(repository);


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
#define _CRTDBG_MAP_ALLOC
#include "UI.h"
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	Repository repository{};
	Repository watchlist{};
	Controller controller{ repository,watchlist };
	UI ui{ controller };
	ui.menu_for_which_mode();
	_CrtDumpMemoryLeaks();

	return 0;
}
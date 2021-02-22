#include "UI.h"

int main()
{
	Repository repository{};
	Controller controller{ repository };
	UI ui{ controller };
	ui.menu_for_which_mode();

	return 0;
}
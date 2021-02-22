#define _CRTDBG_MAP_ALLOC
#include "UI.h"
#include <stdlib.h>
#include <crtdbg.h>
//#include "Tests.h"
#include <iostream>
using namespace std;
int main()
{
	//testAll();
	Start_UI start_ui{};
	string file_path = start_ui.Start1();
	File_Repository repository{file_path};
	
	string my_list_file_path = start_ui.Start2();

	int position = my_list_file_path.rfind(".");

	if (my_list_file_path.substr(position + 1, *(my_list_file_path.end() - 1)) == "html")
	{
		HTML_Repository watchlist{ my_list_file_path };
		Validator validator;
		Controller controller{ repository,&watchlist,validator };
		UI ui{ controller };
		ui.menu_for_which_mode();
		watchlist.display_HTML();
	}
	else if (my_list_file_path.substr(position + 1, *(my_list_file_path.end() - 1)) == "csv")
	{
		CSV_Repository watchlist{ my_list_file_path };
		Validator validator;
		Controller controller{ repository,&watchlist,validator };
		UI ui{ controller };
		ui.menu_for_which_mode();
		watchlist.display_CSV();
	}
	else
	{
		return 0;
	}
	
	
	_CrtDumpMemoryLeaks();


	return 0;
}
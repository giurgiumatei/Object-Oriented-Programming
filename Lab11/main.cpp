#include <QtWidgets/QApplication>
#define _CRTDBG_MAP_ALLOC
#include "Controller.h"
#include "GUI.h"
#include <stdlib.h>
#include <crtdbg.h>
//#include "Tests.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	QApplication application(argc, argv);

	//testAll();
	//Start_UI start_ui{};
	//string file_path = start_ui.Start1();
	File_Repository repository{ "C:\\Users\\giurg\\OneDrive\\Facultate\\OOP\\Lab8\\Lab8\\Lab8\\test.txt" };

	string my_list_file_path = "C:\\Users\\giurg\\OneDrive\\Facultate\\OOP\\Lab8\\Lab8\\Lab8\\test.hml";




	HTML_Repository watchlist{ my_list_file_path };
	Validator validator;
	Controller controller{ repository,&watchlist,validator };
	GUI gui{ controller };
	gui.show();
	//UI ui{ controller };
	//ui.menu_for_which_mode();
	//watchlist.display_HTML();



	return application.exec();
}

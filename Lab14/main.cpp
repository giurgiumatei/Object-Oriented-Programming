#include <QtWidgets/QApplication>
#define _CRTDBG_MAP_ALLOC
#include "Controller.h"
#include <stdlib.h>
#include <crtdbg.h>
//#include "Tests.h"
#include <iostream>
#include "MovieGUI.h"
#include <qdebug.h>
using namespace std;

int main(int argc, char* argv[])
{
	QApplication application(argc, argv);


	ifstream file_line_reader("C:\\Users\\giurg\\OneDrive\\Facultate\\OOP\\Lab12\\configuration.txt");
	string list_file_path, watchlist_file_path, inmemory;

	getline(file_line_reader, inmemory);
	if (inmemory == "True")
	{
		Repository repository;
		getline(file_line_reader, list_file_path);
		getline(file_line_reader, watchlist_file_path);





		int position = watchlist_file_path.rfind(".");

		if (watchlist_file_path.substr(position + 1, *(watchlist_file_path.end() - 1)) == "html")
		{

			HTML_Repository watchlist{ watchlist_file_path };

			Validator validator;
			Controller controller{ &repository,&watchlist,validator };
			MyListTableModel* model =new MyListTableModel{ controller };
			MyListWidget mylist_widget{ model };
			MovieGUI gui{ controller,mylist_widget };
			gui.show();
			return application.exec();


		}
		else if (watchlist_file_path.substr(position + 1, *(watchlist_file_path.end() - 1)) == "csv")
		{
			CSV_Repository watchlist{ watchlist_file_path };
			Validator validator;
			Controller controller{ &repository,&watchlist,validator };
			MyListTableModel* model = new MyListTableModel{ controller };
			MyListWidget mylist_widget{ model };
			MovieGUI gui{ controller,mylist_widget };
			gui.show();
			return application.exec();
		}
		else
		{
			return application.exec();
		}
	}
	else
	{

		getline(file_line_reader, list_file_path);
		File_Repository repository{ list_file_path };
		getline(file_line_reader, watchlist_file_path);





		int position = watchlist_file_path.rfind(".");

		if (watchlist_file_path.substr(position + 1, *(watchlist_file_path.end() - 1)) == "html")
		{

			HTML_Repository watchlist{ watchlist_file_path };

			Validator validator;
			Controller controller{ &repository,&watchlist,validator };
			MyListTableModel* model = new MyListTableModel{ controller };
			MyListWidget mylist_widget{ model };
			MovieGUI gui{ controller,mylist_widget };
			gui.show();
			return application.exec();


		}
		else if (watchlist_file_path.substr(position + 1, *(watchlist_file_path.end() - 1)) == "csv")
		{
			CSV_Repository watchlist{ watchlist_file_path };
			Validator validator;
			Controller controller{ &repository,&watchlist,validator };

			MyListTableModel* model = new MyListTableModel{ controller };
			MyListWidget mylist_widget{ model };
			MovieGUI gui{ controller,mylist_widget };
			gui.show();
			return application.exec();
		}
		else
		{
			return application.exec();
		}
	}
}
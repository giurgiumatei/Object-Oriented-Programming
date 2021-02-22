#include "Cars.h"
#include <QtWidgets/QApplication>
#include "Controller.h"
#include "Tests.h"

int main(int argc, char* argv[])
{
	//Remove "//" from the following line if you want to run the tests, careful at the file input
	//test_all(); 
	QApplication a(argc, argv);
	Repository repository("C:\\Users\\giurg\\OneDrive\\Facultate\\OOP\\Cars\\Cars\\test.txt");
	Controller controller(repository);
	Cars gui(controller);
	gui.show();
	return a.exec();
}

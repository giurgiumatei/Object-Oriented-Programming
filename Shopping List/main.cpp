#include "ShoppingList.h"
#include <QtWidgets/QApplication>
#include "Controller.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repository("C:\\Users\\giurg\\OneDrive\\Facultate\\OOP\\Shopping List\\Shopping List\\test.txt");
	Controller controller(repository);
	ShoppingList gui(controller);
	gui.show();
	return a.exec();
}

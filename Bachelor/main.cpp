#include "Bachelor.h"
#include <QtWidgets/QApplication>
#include "Service.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository<Student> students_list("Students.txt");
    Repository<Teacher> students_list("Teachers.txt");
    Bachelor w;
    w.show();
    return a.exec();
}

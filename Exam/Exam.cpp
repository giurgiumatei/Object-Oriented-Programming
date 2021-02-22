#include "Exam.h"
#include <qmessagebox.h>
Exam::Exam(Controller& controller,QWidget *parent)
    :controller(controller), QMainWindow(parent)
{
    ui.setupUi(this);
    this->populate_list();
}

void Exam::populate_list()
{
    this->ui.entity_list_widget->clear();
    vector<Entity> entity_list = this->controller.get_data();

    for (auto& entity:entity_list)
    {

        QString information = QString::fromStdString(entity.get_first_string() + " | " + entity.get_second_string() + " | " + to_string(entity.get_first_int()));
        QListWidgetItem* dataline = new QListWidgetItem();
        dataline->setText(information);
        this->ui.entity_list_widget->addItem(dataline);

    }
}

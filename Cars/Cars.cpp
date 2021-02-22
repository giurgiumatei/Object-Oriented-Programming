#include "Cars.h"
#include <qmessagebox.h>
Cars::Cars(Controller& controller,QWidget *parent)
    : controller(controller),QMainWindow(parent)
{
    ui.setupUi(this);
    this->populate_list();
}

void Cars::populate_list()
{
    this->ui.cars_list_widget->clear();
    vector<Car> cars_list = this->controller.get_data_sorted();

    for (auto& car : cars_list)
    {
        QString information = QString::fromStdString(car.get_manufacturer() + " | " +car.get_model());
        QListWidgetItem* dataline = new QListWidgetItem();
        dataline->setText(information);
        if (car.get_color() == "black") {
            dataline->setForeground(QBrush(QColor(Qt::GlobalColor::black)));
            
        }
        else if (car.get_color() == "blue") {
            dataline->setForeground(QBrush(QColor(Qt::GlobalColor::blue)));
            
        }
        else if (car.get_color() == "red") {
            dataline->setForeground(QBrush(QColor(Qt::GlobalColor::red)));
           
        }
        else if (car.get_color() == "yellow") {
            dataline->setForeground(QBrush(QColor(Qt::GlobalColor::yellow)));
            dataline->setBackground(QBrush(QColor(Qt::GlobalColor::red)));
        }
        else if (car.get_color() == "green") {
            dataline->setForeground(QBrush(QColor(Qt::GlobalColor::green)));
        }
        this->ui.cars_list_widget->addItem(dataline);
    }
}

void Cars::filter()
{
    string name = this->ui.name_line_edit->text().toStdString();

    int count = this->controller.get_number_of_cars_filtered_by_name(name);

    QMessageBox::information(this, QString::fromStdString("Number of Cars"), QString::fromStdString(to_string(count)));
}

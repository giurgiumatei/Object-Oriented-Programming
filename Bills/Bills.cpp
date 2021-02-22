#include "Bills.h"
#include "qmessagebox.h"
Bills::Bills(Controller& controller,QWidget *parent)
    :controller{ controller }, QMainWindow(parent)
{
    ui.setupUi(this);
    this->populate_list();
}




void Bills::populate_list()
{
    this->ui.bills_list_widget->clear();
    vector<Bill> bills_list = this->controller.get_data();

    for (auto bill : bills_list)
    {

        this->ui.bills_list_widget->addItem(QString::fromStdString(bill.get_name() + " - " + std::to_string(bill.get_sum())));
    }
}

void Bills::total()
{
    string name = this->ui.total_line_edit->text().toStdString();

    vector<Bill> bills_list = this->controller.get_data();
    float total_sum=0;
    for (auto bill : bills_list)
    {
        if (bill.get_name() == name)
        {
            total_sum += bill.get_sum();
        }
    }

    QMessageBox::information(this, QString::fromStdString("Total Sum"), QString::fromStdString(to_string(total_sum)));
}

void Bills::populate_sorted()
{

    this->ui.bills_list_widget->clear();
    vector<Bill> bills_list = this->controller.get_sorted_data();

    for (auto bill : bills_list)
    {

        this->ui.bills_list_widget->addItem(QString::fromStdString(bill.get_name() + " - " + std::to_string(bill.get_sum())));
    }
}

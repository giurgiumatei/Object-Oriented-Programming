#include "Vegetables.h"
#include <qdebug.h>
#include <qmessagebox.h>
Vegetables::Vegetables(Controller& controller,QWidget *parent)
    : controller(controller),QMainWindow(parent)//{} ?
{
    ui.setupUi(this);
    this->populate_family_list();
    this->index_of_current = 0;
}

void Vegetables::populate_family_list()
{
    this->ui.family_list_widget->clear();
    set<string> family_list = this->controller.get_families();

    for (string family: family_list)
    {

        this->ui.family_list_widget->addItem(QString::fromStdString(family));
    }
}

void Vegetables::select_item()
{
    int selected_index = this->get_selected_index();
    
    if (selected_index < 0)
    {
        return;
    }
    set<string> families = this->controller.get_families();
    set<string>::iterator it = families.begin();
    std::advance(it, selected_index);
    string family = *it;
    this->ui.vegetables_list_widget->clear();
    vector<Vegetable> vegetables=this->controller.get_data();

    for (auto vegetable : vegetables)
    {
        if (vegetable.get_family() == family)
        {
            this->ui.vegetables_list_widget->addItem(QString::fromStdString(vegetable.get_name()+ " | " + vegetable.get_parts()));
        }
    }
}

int Vegetables::get_selected_index()
{
    QModelIndexList selected_indexes = this->ui.family_list_widget->selectionModel()->selectedIndexes();
    int selected_index = selected_indexes.at(0).row();

    

    return selected_index;
}

void Vegetables::search()
{
    string name= this->ui.vegetable_line_edit->text().toStdString();
    bool found = false;
    vector<Vegetable> vegetables = this->controller.get_data();
    int index = 0;
    for (auto vegetable : vegetables)
    {
        if (vegetable.get_name() == name)
        {
            this->ui.parts_line_edit->setText(QString::fromStdString(vegetable.get_parts()));
            found = true;
           
            set<string> family_list = this->controller.get_families();

            for (string family : family_list)
            {
                if (vegetable.get_family() == family)
                {
                    break;
                }
                else{
                
                index++;
                }
            }
            this->ui.family_list_widget->setCurrentRow(index);
            this->ui.family_list_widget->setFocus();
            break;
        }
    }

    if (found == false)
    {
        QMessageBox::critical(this, "Error", "Vegetable not found! ");
        return;
    }
}

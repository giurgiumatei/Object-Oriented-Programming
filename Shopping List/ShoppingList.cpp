#include "ShoppingList.h"
#include <qmessagebox.h>
#include <qdebug.h>
ShoppingList::ShoppingList(Controller& controller,QWidget *parent)
	: QMainWindow(parent),controller {controller}
{
	ui.setupUi(this);
	this->populate_list();
	this->index_of_current = 0;
	
}

void ShoppingList::select_item()
{
	int selected_index = this->get_selected_index();
	if (selected_index < 0)
	{
		return;
	}
	Item item = this->controller.get_shopping_list()[selected_index];
	this->ui.category_line_edit->setText(QString::fromStdString(item.get_category()));
	this->ui.name_line_edit->setText(QString::fromStdString(item.get_name()));
	this->ui.quantity_line_edit->setText(QString::fromStdString(std::to_string(item.get_quantity())));
	

}



int ShoppingList::get_selected_index()
{
	QModelIndexList selected_indexes = this->ui.item_list_widget->selectionModel()->selectedIndexes();
	if (selected_indexes.size() == 0)
	{
		this->ui.category_line_edit->clear();
		this->ui.name_line_edit->clear();
		this->ui.quantity_line_edit->clear();
		return -1;
	}

	int selected_index = selected_indexes.at(0).row();

	return selected_index;
}

void ShoppingList::populate_list()
{
	this->ui.item_list_widget->clear();
	vector<Item> item_list = this->controller.get_shopping_list();

	for (Item& item : item_list)
	{

		this->ui.item_list_widget->addItem(QString::fromStdString(item.get_category() + " | " + item.get_name() + " | " + std::to_string(item.get_quantity())));
	}
}

void ShoppingList::add()
{
	string category = this->ui.category_line_edit->text().toStdString();
	string name = this->ui.name_line_edit->text().toStdString();
	string quantity_string= this->ui.quantity_line_edit->text().toStdString();
	int quantity = stoi(quantity_string);

	Item item(category, name, quantity);
	controller.add(item);
	this->populate_list();
	int last_element = this->controller.get_shopping_list().size() - 1;
	this->ui.item_list_widget->setCurrentRow(last_element);
}

void ShoppingList::remove()
{
	int selected_index = this->get_selected_index();

	if (selected_index < 0)
	{
		QMessageBox::critical(this, "Error", "No movie was selected! ");
		return;
	}

	string name = this->controller.get_shopping_list()[selected_index].get_name();

	Item item_to_be_removed("", name, 0);
	
		this->controller.remove(item_to_be_removed);

		this->populate_list();
}

void ShoppingList::filter()
{
	this->ui.item_list_widget->clear();
	string category= this->ui.filter_line_edit->text().toStdString();
	vector<Item> filtered_list = controller.filter(category);

	for (Item& item : filtered_list)
	{

		this->ui.item_list_widget->addItem(QString::fromStdString(item.get_category() + " | " + item.get_name() + " | " + std::to_string(item.get_quantity())));
	}
}

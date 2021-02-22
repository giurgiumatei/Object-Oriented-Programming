#include "MyListWidget.h"

MyListWidget::MyListWidget(MyListTableModel* model, QWidget* parent)
	: QWidget(parent), model{ model }
{
	ui.setupUi(this);
	ui.mylist_table_view->setModel(this->model);
}


void MyListWidget::add_in_MyList(const string& title)
{
	this->model->add_in_MyList(title);
}

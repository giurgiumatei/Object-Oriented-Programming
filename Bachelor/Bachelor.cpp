#include "Bachelor.h"

Bachelor::Bachelor(Teacher& teacher, Service& service,QWidget *parent)
    : QMainWindow(parent),teacher{teacher},service{service}
{
    ui.setupUi(this);
}

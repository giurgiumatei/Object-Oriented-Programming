#pragma once
#include "Controller.h"




typedef struct {

	Controller* controller;


}UI;


UI* createUI(Controller* controller);

void startUI(UI* ui);


void printMenu();
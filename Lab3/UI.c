#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "UI.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
UI* createUI(Controller* controller)
{
	UI* ui = (UI*)malloc(sizeof(UI));
	ui->controller = controller;

	return ui;
}


void printMenu()
{
	printf("\n**********************************************************\n");
	printf("add a material: \n");
	printf("delete a material: \n");
	printf("update a material: \n");
	printf("list the materials: \n");
	printf("list the materials containing a given string: \n");
	printf("exit.\n");
	printf("\n**********************************************************\n");
}



//exit(0); daca comanda e 0


void startUI(UI* ui)
{
	
	while (1)
	{
		char* command;
		command = (char*)malloc(100 * sizeof(char));
		printMenu();
		scanf("%[^\n]%*c", command);
		
		
		char* token = strtok(command, " \n");

		

		if (strcmp(token,"add")== 0)
		{
			token = strtok(NULL, ", ");
			

			int id = atoi(token);

			token = strtok(NULL, ", ");
			

			char* supplier = token;

			token = strtok(NULL, ", ");

			

			char* name = token;

			token = strtok(NULL, " \n \t \0 , ");
			
			int quantity;
			
			quantity=atoi(token);

			if (addProductController(ui->controller, id, supplier, name, quantity) == 0)
			{
				printf("No!");

			}
		}

		else if (strcmp(token,"delete")==0)
		{
			token = strtok(NULL, ", ");

			int id = atoi(token);

			

			if (removeProductController(ui->controller, id) == 0)
			{
				printf("No!");

			}

		}

		else if (strcmp(token,"update")==0)
		{
			token = strtok(NULL, ", ");

			int id = atoi(token);

			token = strtok(NULL, ", ");

			char* supplier = token;

			token = strtok(NULL, ", ");

			char* name = token;
			
			token = strtok(NULL, " \n \t \0 , ");

			int quantity = atoi(token);

			if (updateProductController(ui->controller, id, supplier, name, quantity) == 0)
			{
				printf("No!");

			}


		}

		else if (strcmp(token,"list")==0)
		{	
			Repository* list;

			list = getListController(ui->controller);

			//printf("%d", getID(list->materials[0]));

			for (int i = 0; i < list->lenght; i++)
			{
				printf("%d ", getID(list->materials[i]));
				printf("%s ", getSupplier(list->materials[i]));
				printf("%s ", getName(list->materials[i]));
				printf("%d ", getQuantity(list->materials[i]));


			}


		}

		else if (strcmp(token,"list name")==0)
		{
			Repository* list;

			token = strtok(NULL, "\n");

			list = getListController(ui->controller);

			for (int i = 0; i < list->lenght; i++)
			{

				if (strstr(getName(list->materials[i]), token))
				{
					printf("%d ", getID(list->materials[i]));
					printf("%s ", getSupplier(list->materials[i]));
					printf("%s ", getName(list->materials[i]));
					printf("%d ", getQuantity(list->materials[i]));
				}


			}


		}

		else if (strcmp(token,"exit")== 0)
		{
			break;
			

		}



	}

}

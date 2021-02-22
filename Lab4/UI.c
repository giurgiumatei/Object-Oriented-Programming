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

		else if (strcmp(token, "list") == 0)
		{

			int counter = 0;

			if (token != NULL )
			{
				token = strtok(NULL, " \n \t \0 , ");
				counter += 1;
				printf("%s aici\n", token);
			}

			counter -= 1;
			if (token==NULL)


			{
				Material* materials = getMaterialsDataController(ui->controller);


				for (int i = 0; i < getLenghtController(ui->controller); i++)
				{


					printf(" %d ", getID(&materials[i]));
					printf(" %s ", getName(&materials[i]));
					printf(" %s ", getSupplier(&materials[i]));
					printf(" %d ", getQuantity(&materials[i]));


				}
			}

			else if (strcmp(token, "name")==0)
			{
				
				
				token = strtok(NULL, " \n \t \0 , ");
				Material* materials = getMaterialsDataController(ui->controller);

				for (int i = 0; i < getLenghtController(ui->controller); i++)
				{


					if (strcmp(getName(&materials[i]), token)==0)

					{


						printf(" %d ", getID(&materials[i]));
						printf(" %s ", getName(&materials[i]));
						printf(" %s ", getSupplier(&materials[i]));
						printf(" %d ", getQuantity(&materials[i]));


					}



				}


			}

			else
			{
				


				int max_quantity = atoi(token);

				Material* materials = getMaterialsDataController(ui->controller);

				materials = sortListAlphabetically(ui->controller, materials);

				for (int i = 0; i < getLenghtController(ui->controller); i++)
				{
					if (getQuantity(&materials[i]) < max_quantity)

					{
						printf(" %d ", getID(&materials[i]));
						printf(" %s ", getName(&materials[i]));
						printf(" %s ", getSupplier(&materials[i]));
						printf(" %d ", getQuantity(&materials[i]));
					}

				}
			}

		}


		else if (strcmp(token,"exit")== 0)
		{
			break;
			

		}

		else if (strcmp(token, "undo") == 0)
		{

			if (undoControllerFunction(ui->controller) == false)
			{
				printf("No more Undos! ");
				

			}

		}

		else if (strcmp(token, "redo") == 0)
		{

			if (redoControllerFunction(ui->controller) == false)
			{
				printf("No more Redos! ");


			}

		}



	}

}

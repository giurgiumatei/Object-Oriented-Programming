#define _CRT_SECURE_NO_WARNINGS
#include "Domain.h"
#include <string.h>
#include <stdlib.h>


Material createMaterial(int id,char *supplier,char *name,int quantity)
{
	Material material;

	material.id = id;

	material.quantity = quantity;

	material.supplier = (char*)malloc(64 * sizeof(char));
	material.name = (char*)malloc(64 * sizeof(char));
	strcpy(material.supplier, supplier); 
	strcpy(material.name, name);

	return material;


}


void free_material_memory_leaks(Material material)
{

	free(material.supplier);
	free(material.name);


}


char *getName(Material material)
{

	return material.name;

}

char *getSupplier(Material material)
{
	return material.supplier;

}

int getID(Material material)
{
	return material.id;

}

int getQuantity(Material material)
{
	return material.quantity;

}





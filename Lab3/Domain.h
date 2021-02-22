#pragma once


typedef struct {

	int id, quantity;
	char *supplier, *name;


}Material;



Material createMaterial(int id,char *supplier,char *name,int quantity);

void free_material_memory_leaks(Material material);

char *getName(Material* material);

char *getSupplier(Material* material);

int getID(Material* material);

int getQuantity(Material* material);






#pragma once
#define MAX_SIZE 128
#include "Domain.h"


typedef struct {

	Material materials[MAX_SIZE];
	int lenght;



}Repository;


Repository* createRepository();

//int hasMaterial(Repository* repository, Material material);

void addMaterial(Repository* repository, Material material);

void removeMaterial(Repository* repository, int id);

void updateMaterial(Repository* repository, Material material);

Repository* getList(Repository* repository);

int hasMaterialbyID(Repository* repository, int id);
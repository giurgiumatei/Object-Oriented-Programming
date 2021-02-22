#include "Repository.h"
#include <string.h>
#include <stdlib.h>


Repository* createRepository()
{

	Repository* list = (Repository*)malloc(sizeof(Repository));
	list->lenght = 0;

	return list;


}
/*
int hasMaterial(Repository* repository, Material material)
{
	for (int i = 0; i < repository->lenght; ++i) 
	{

		if (strcmp(getName(repository->materials[i]), getName(material)) == 0)
		{
			return 1;
		}
	}

		return 0;
}
*/

int hasMaterialbyID(Repository* repository, int id)
{
	for (int i = 0; i < repository->lenght; ++i)
	{
		if (getID(repository->materials[i]) == id)
		{
			return 1;
		}

	}

	return 0;

}



void addMaterial(Repository* repository, Material material)
{

	repository->materials[repository->lenght] = material;
	repository->lenght += 1;

}


void removeMaterial(Repository* repository, int id)
{
	for (int i = 0; i < repository->lenght; ++i)
	{
		if (getID(repository->materials[i]) == id)
		{	
			free_material_memory_leaks(repository->materials[i]);
			for (int j = i; j < repository->lenght - 1; j++)
			{
				repository->materials[j] = repository->materials[j + 1];


			}

			repository->lenght -= 1;
			break;


		}

	}

}


void updateMaterial(Repository* repository, Material material)
{

	for (int i = 0; i < repository->lenght; ++i)
	{
		if (getID(repository->materials[i]) == getID(material))
		{
			repository->materials[i] = material;
			break;
		}
	}
}


Repository* getList(Repository* repository)


{
	
	return repository;
}




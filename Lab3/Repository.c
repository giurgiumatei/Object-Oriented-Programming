#include "Repository.h"
#include <string.h>
#include <stdlib.h>


Repository* createRepository()
{

	Repository* list = (Repository*)malloc(sizeof(Repository));
	list->lenght = 0;

	return list;


}


int hasMaterialbyID(Repository* repository, int id)
{
	for (int i = 0; i < repository->lenght; ++i)
	{
		if (getID(&repository->materials[i]) == id)
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


Material removeMaterial(Repository* repository, int id)
{
	Material material_removed;

	for (int i = 0; i < repository->lenght; ++i)
	{
		if (getID(&repository->materials[i]) == id)
		{	
			
			

			material_removed = repository->materials[i];

			for (int j = i; j < repository->lenght - 1; j++)
			{
				repository->materials[j] = repository->materials[j + 1];

			}

			repository->lenght -= 1;
			
			return material_removed;


		}

	}
	return;
}


Material updateMaterial(Repository* repository, Material material)
{
	Material material_updated;

	for (int i = 0; i < repository->lenght; ++i)
	{
		if (getID(&repository->materials[i]) == getID(&material))
		{
			material_updated = repository->materials[i];
			repository->materials[i] = material;
			return material_updated;
		}
	}
	
}


Repository* getList(Repository* repository)


{
	
	return repository;
}

int getLenght(Repository* repository)
{
	return repository->lenght;

}


Material* getMaterialsData(Repository* repository)
{
	

	return &repository->materials;


}






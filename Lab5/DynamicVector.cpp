#pragma once
#include "DynamicVector.h"

/*
void DynamicVector::resize()
{

	this->capacity *= 2;

	

	TElem* aux = new TElem[this->capacity];

	for (int i = 0; i < this->size; i++)
	{
		aux[i] = this->elements[i];
	}

	delete[] this->elements;

	this->elements = aux;
}

DynamicVector::DynamicVector(int capacity)
{
	this->capacity = capacity;
	this->size = 0;
	this->elements = new T[this->capacity];


}


DynamicVector::DynamicVector(const DynamicVector& vector)
{
	this->capacity = vector.capacity;

	this->size = vector.size;

	this->elements = new TElem[this-> capacity];

	for (int i = 0; i< this->size; i++)
	{
		this->elements[i] = vector.elements[i];
	}



}

const DynamicVector& DynamicVector::operator=(const DynamicVector& vector)
{
	if (this == &vector)
	{
		return *this;
	}

	this->capacity = vector.capacity;
	this->size = vector.size;

	delete[] this->elements;

	this->elements = new TElem[this->capacity];

	for (int i = 0; i < this->size; i++)
	{
		this->elements[i] = vector.elements[i];
	}

	return *this;

}





DynamicVector::~DynamicVector()
{

	delete[] this->elements;


}

void DynamicVector::add(TElem element)
{
	if (this->size == this->capacity)
	{
		this->resize();
	}

	this->elements[this->size++] = element;
}
*/
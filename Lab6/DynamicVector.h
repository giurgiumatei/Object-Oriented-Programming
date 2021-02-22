#pragma once
#include "Domain.h"
#include <iostream>
using std::cout;

template <class Element>

class DynamicVector
{
private:

	int capacity, lenght;
	Element* elements;


	void resize();

public:

	DynamicVector(int capacity = 10);
	DynamicVector(const DynamicVector& vector);
	const DynamicVector& operator=(const DynamicVector& vector);
	~DynamicVector();

	void add(Element element);
	void remove(string title);
	bool update(Element element);
	bool is_in_list(string title);
	Element* get_elements_data();
	int get_lenght();



};


template <class Element>
int DynamicVector<Element>::get_lenght()
{
	return this->lenght;

}




template <class Element>
void DynamicVector<Element>::resize()
{

	this->capacity *= 2;



	Element* glass = new Element[this->capacity];

	for (int i = 0; i < this->lenght; i++)
	{
		glass[i] = this->elements[i];
	}

	delete[] this->elements;

	this->elements = glass;
}

template <class Element>
DynamicVector<Element>::DynamicVector(int capacity)
{
	this->capacity = capacity;
	this->lenght = 0;
	this->elements = new Element[this->capacity];


}

template <class Element>
DynamicVector<Element>::DynamicVector(const DynamicVector& vector)
{
	this->capacity = vector.capacity;

	this->lenght = vector.lenght;

	this->elements = new Element[this->capacity];

	for (int i = 0; i < this->lenght; i++)
	{
		this->elements[i] = vector.elements[i];
	}



}


template <class Element>
const DynamicVector<Element>& DynamicVector<Element>::operator=(const DynamicVector& vector)
{
	if (this == &vector)
	{
		return *this;
	}

	this->capacity = vector.capacity;
	this->lenght = vector.lenght;

	delete[] this->elements;

	this->elements = new Element[this->capacity];

	for (int i = 0; i < this->lenght; i++)
	{
		this->elements[i] = vector.elements[i];
	}

	return *this;

}




template <class Element>
DynamicVector<Element>::~DynamicVector()
{

	delete[] this->elements;


}

template <class Element>
void DynamicVector<Element>::add(Element element)
{
	if (this->lenght == this->capacity)
	{
		this->resize();
	}

	this->elements[this->lenght++] = element;
}


template <class Element>
void DynamicVector<Element>::remove(string title)
{	
	
	
	for (int i = 0; i < this->lenght; i++)
	{
		if (this->elements[i].get_title() == title)
		{
			for (int j = i; j < this->lenght - 1; j++)
			{
				this->elements[j]=this->elements[j+1];

			}

			this->lenght-=1;

		}

	}
	
}

template <class Element>
bool DynamicVector<Element>::update(Element element)
{
	

	for (int i = 0; i < this->lenght; i++)
	{
		if (this->elements[i].get_title() == element.get_title())
		{
			this->elements[i]=element;
			return true;
			break;

		}

	}
	return false;
}

template<class Element>

bool DynamicVector<Element>::is_in_list(string title)
{
	for (int i = 0; i < this->lenght; i++)
	{
		if (this->elements[i].get_title() == title)
		{
			return true;

		}

	}

	return false;
}

template <class Element>
Element* DynamicVector<Element>::get_elements_data()
{

	return this->elements;

}
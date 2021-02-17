#pragma once
#include<iostream>
template<typename T>
class Vector
{
private:
	T* data;
	size_t size, capacity;
	void copy(const Vector<T>& other);
	void destroy();
public:
		Vector<T>();
		Vector<T>(const Vector<T>& other);
		Vector<T> operator=(const Vector<T>& other);
		~Vector<T>();

};
template<typename T>
Vector<T>::Vector()
{
	size = 0;
	capacity = 8;
	data = new T[capacity];
}
template<typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	this->copy(other);
}
template <typename T>
Vector<T> Vector<T>::operator= (const Vector<T>& other)
{
	if (this != &other)
	{
		delete[] this->data;
		this->copy(other);
	}
	return *this;
}
template<typename T>
Vector<T>::~Vector()
{
	delete[] data;
	size = 0;
	capacity = 0;
}

template <typename T>
Vector<T>::~Vector()
{
	destroy();
}

template <typename T>
void Vector<T>::destroy()
{
	delete[] data;
}

template <typename T>
void Vector<T>::copy(const Vector<T>& other)
{
	this->capacity = other.capacity;
	this->size = other.size();
	for (int i = 0; i < size; i++)
	{
		this->data[i] = other.data[i];
	}
}
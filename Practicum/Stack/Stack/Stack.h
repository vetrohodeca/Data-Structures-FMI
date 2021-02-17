#pragma once
template <typename T>
class Stack
{
private:
	T* stackArray;
	unsigned int capacity;
	unsigned int size;
	void copy(const Stack& other) {

		this->capacity = other.capacity;
		this->size = other.size;
		stackArray = new T[capacity]; //! vajno
		for (int i = 0; i < this->size; i++)
		{
			this->stackArray[i] = other.stackArray[i];
		}
	}
	void clear() {
		delete[] stackArray;
		this->capacity = 0;
		this->size = 0;
	}
	void resize() {
		capacity *= 2;
		T* newArray = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			newArray[i] = stackArray[i];
		}
		clear();
		stackArray = newArray;
	}

public:
	Stack() {
		this->size = 0;
		this->capacity = 8;
		this->stackArray = new T[8];
	}

	Stack(const Stack& other) {
		copy(other);
	}

	Stack& operator=(const Stack& other) {
		if (this != other) {
			clear();
			copy(other);
		}
		return *this;
	}

	~Stack() {
		clear();
	}

	void push(const T& data) {
		if (size == capacity) {
			resize();
		}
		stackArray[size] = data;
		this->size++;
	}
	
	void pop() {
		size--;
	}
	T& top() const {
		return stackArray[size - 1];
	}

	unsigned int getSize() {
		return this->size;
	}

	bool IsEmpty() {
		return this->size == 0;
	}
};
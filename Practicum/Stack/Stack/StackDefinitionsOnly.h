#pragma once
template <typename T>
class Stack
{
private:
	T* stackArray;
	unsigned int capacity;
	unsigned int size;
	void copy(const Stack& other);
	void clear ();
	void resize();

public:
	Stack();
	Stack(const Stack& other);
	Stack& operator=(const Stack& other);
	~Stack();

	void push(const T& data);
	void pop();
    T& top() const;

	unsigned int getSize();
	bool IsEmpty();
};
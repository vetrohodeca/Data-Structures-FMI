#include"DLL.h"
DLL::DLL()
{
	this->first = nullptr;
	this->last = nullptr;
}

DLL::DLL(DLL& other)
{
	copy(other);
}

DLL& DLL::operator=(DLL& other)
{
	if (this != &other)
	{
		this->clear();
		this->copy(other);
	}
	return *this;
}

DLL::~DLL()
{
	clear();
}

void DLL::copy(DLL& other)
{
	this->first = new Node(other.first->data);
	Node* copy = other.first;
	Node* cur = this->first;

	while (copy->next != nullptr)
	{
		cur->next = new Node(copy->next->data);
		cur->next->prev = cur;
		cur = cur->next;
		copy = copy->next;
	}
}

void DLL::clear()
{
	Node* temp = nullptr;
	while (first != nullptr)
	{
		temp = new Node(first->data);
		first = first->next;
	}
	this->last = nullptr;
}

void DLL::insert( char* data)
{
	if (this->first == nullptr)
	{
		this->first = new Node(data);
	}
	else
	{
		Node* temp = new Node(data, nullptr, this->first);
		this->first->prev = temp;
		this->first = temp;
	}
}


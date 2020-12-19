#pragma once
#pragma once
class SLinkedList
{
private:
	struct  Node
	{
		int data;
		Node* next;
		Node(const int& data, Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};
	Node* first;
	void copy(const SLinkedList& other);
	void clear();
public:

	SLinkedList();
	SLinkedList(const SLinkedList& ohter);
	SLinkedList& operator=(const SLinkedList& other);
	~SLinkedList();

};

void SLinkedList::copy(const SLinkedList& other)
{
	this->first = new Node(other.first->data);
	Node* copy = other.first;
	Node* cur = this->first;
	while (copy->next != nullptr)
	{
		cur->next = copy->next;
		copy = copy->next;
		cur = cur->next;
	}
}

void SLinkedList::clear()
{
	Node* temp = nullptr;
	while (this->first != nullptr)
	{
		temp = new Node(first->data);
		first = first->next;
		delete temp;
	}
	this->first = nullptr;
}

SLinkedList::SLinkedList()
{
	this->first = nullptr;
}
SLinkedList::SLinkedList(const SLinkedList& other)
{
	this->copy(other);
}
SLinkedList& SLinkedList::operator=(const SLinkedList& other)
{
	if (this != &other)
	{
		this->clear();
		this->copy(other);
	}
	return *this;
}
SLinkedList::~SLinkedList()
{
	SLinkedList::clear();
}
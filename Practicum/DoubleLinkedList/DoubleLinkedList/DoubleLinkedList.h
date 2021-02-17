#pragma once
class DoubleLinkedList
{
private:
	struct Node
	{
		int data;
		Node* next;
		Node* prev;
		Node(const int& data, Node* prev = nullptr, Node* next = nullptr)
		{
			this->data = data;
			this->prev = prev;
			this->next = next;
		}
	};
	Node* first;
	Node* last;
	void copy(const DoubleLinkedList& other);
	void clear();
	void clearReverse();
public:
	DoubleLinkedList();
	DoubleLinkedList(const DoubleLinkedList& other);
	const DoubleLinkedList& operator= (const DoubleLinkedList& other);
	~DoubleLinkedList();

	void insertFront(const int other);
	void instertBack(const int other);
	void insertBefore(int data, const int other);
	void reverse();
};
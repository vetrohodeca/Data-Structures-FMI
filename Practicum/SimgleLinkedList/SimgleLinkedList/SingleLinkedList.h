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
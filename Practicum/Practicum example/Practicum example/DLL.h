#pragma once
struct Node
{
	char* data;
	Node* prev;
	Node* next;

	Node(char* data, Node* prev = nullptr, Node* next = nullptr)
	{
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
};
class DLL
{
private:

	Node* first, * last;
	void copy(DLL& other);
	void clear();
public:
	DLL();
	DLL(DLL& other);
	DLL& operator=(DLL& other);
	~DLL();
	void insert( char* data);
};
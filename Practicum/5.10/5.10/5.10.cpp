#include <iostream>

class SLinkList
{
public:
	struct Node
	{
		int data;
		Node* next;

		Node(const int& data, Node* next = nullptr) //! Задаваме дефоултна стойност когато инициализираме нещо с равно, всчико след това трябва да е с равно
		{
			this->data = data;
			this->next = next;
		}
		void pushBack(Node*& first, int data)// Защо указателя се подава по референиця
		{
			if (first == nullptr)
			{
				first = new Node(data);
				return;
			}
			Node* cur = first;
			while (cur->next != nullptr)
			{
				cur = cur->next;
			}
			cur->next = new SLinkList::Node(data);
		}

		void print(Node* first)
		{
			Node* cur = first;
			while (cur != nullptr)
			{
				std::cout << cur->data << " ";
				cur = cur->next;
			}
		}
	};
	SLinkList()
	{
		this->first = nullptr;
	}
	SLinkList(const SLinkList& other)
	{
		this->copy(other);
	}
	SLinkList& operator=(const SLinkList& rhs)
	{
		if (this != &rhs)
		{
			this->clear();
			this->copy(rhs);
		}
		return*this;
	}
	~SLinkList()
	{
		this->clear();
	}

	void swapSecond(Node& first, int element)
	{

	}
private:
	Node* first;
	void copy(const SLinkList& rhs)
	{
		//Node* newBox = new Node(rhs.first->data);
		//this->first = newBox;
		this->first = new Node(rhs.first->data);

		Node* copy = rhs.first;
		Node* cur = this->first;

		//Node* tempBox = nullptr;
		while (copy->next != nullptr)
		{
			//tempBox = new Node(copy->next->data);
			//cur->next= tempBox; 
			cur->next = new Node(copy->next->data);
			copy = copy->next;
			cur = cur->next;
		}
	}

	void clear()
	{
		Node* temp = nullptr;
		while (first != nullptr)
		{
			temp = new Node(first->data);
			first = first->next;
			delete temp;
		}
	}
	//size_t size;
};

int main()
{
	std::cout << "Hello World!\n";
	SLinkList::Node* first = nullptr;
	first->pushBack(first, 5);
	first->pushBack(first, 1);
	first->pushBack(first, 2);
	first->print(first);
	return 0;
}


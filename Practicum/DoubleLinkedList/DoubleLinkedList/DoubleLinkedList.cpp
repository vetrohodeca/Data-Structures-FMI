#include "DoubleLinkedList.h"

void DoubleLinkedList::copy(const DoubleLinkedList& other)
{
	this->first = new Node(other.first->data);// zadavame stoinostta na purviq ni element
	Node* curr = this->first; // tekushtiq ni e purviq
	Node* copy = other.first; // tekushtiq ot koito vzimame ni e purvoq
	while (other.last != nullptr)
	{
		curr->next = new Node(copy->next->data);// sledvashtiq ni elemenmt e nova kletka ot na kopi stoinostta
		curr->next->prev = curr;// na sledvashtiq predishniq ni e tekushtiq
		curr = curr->next; // minavame na sledvashtiq element
		copy = copy->next; // minavame na sledvashtiq element, ot koito vzimame
	}
}

//first i last - ukazateli kum purviq i posledniq vinagi
//prev i next - ukazateli kum tekushtiq i 
void DoubleLinkedList::clear()
{
	Node* curr = nullptr;
	while (this->first != nullptr)// dokato ima purvi element
	{
		curr = new Node(this->first->data);// pravim si tekusht =  datata na purviq element
		first = first->next;
		delete curr;
	}
	this->last = nullptr;
}

void DoubleLinkedList::clearReverse()
{
	Node* curr = nullptr;
	while (this->last != nullptr)
	{
		curr = new Node(this->last->data);
		last = last->prev;
		delete curr;
	}
	this->first = nullptr;
}

DoubleLinkedList::DoubleLinkedList()
{
	this->first = nullptr;
	this->last = nullptr;
}
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& other)
{
	this->copy(other);
}
const DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList& other)
{
	if (this != &other)
	{
		this->clear();
		this->copy(other);
	}
	return *this;
}
DoubleLinkedList::~DoubleLinkedList()
{
	this->clear();
}

void DoubleLinkedList::insertFront(const int other)
{
	if (this->first == nullptr)
	{
		this->first = new Node(other);
	}
	else
	{
		Node* temp = new Node(other, nullptr, this->first);
		this->first->prev = temp;
		this->first = temp;
	}
}

void DoubleLinkedList::instertBack(const int other)
{
	if (this->first == nullptr)
	{
		this->first = new Node(other);
	}
	else
	{
		Node* temp = new Node(other, this->last, nullptr);
		this->last->next = temp;
		this->last = temp;
	}
}

void DoubleLinkedList::insertBefore(int beforeData, const int data)
{
	Node* cur = this->first;
	while (cur!= nullptr&&cur->data!= beforeData)//mestim s 1 nadqsno
	{
		cur = cur->next;
	}
	if (cur->prev == nullptr)// 1 element
	{
		Node* newNode = new Node(data,nullptr, cur);// pravim si purvi node s sledvasht element tekushtiq-- zasshto ne e predishniq?
		cur->prev = newNode;// predishniq element na tekushtiq element e newNode
		this->first = newNode;// slagame ukazatelq
	}
	else
	{
		Node* newNode = new Node(data, cur->prev, cur);// pravim si kutiikata s ukazatelite ot neq kum drugite elementi
		cur->prev->next = newNode; //zakachame otzad
		cur->prev = newNode; // zakachame otpred
	}
}

void DoubleLinkedList::reverse()
{
	Node* cur = this->first;//nachalen element
	Node* copy = nullptr;//swap promenliva
	while (cur != nullptr)
	{
		copy = cur->prev;
		cur->prev = cur->next;
		cur->next = copy;// s tezi 3 reda swapvame prev i next na tekushtiq element
		cur = cur->prev;//iteraciq
	}
	if (copy != nullptr)
	{
		first = copy->prev;
	}
}
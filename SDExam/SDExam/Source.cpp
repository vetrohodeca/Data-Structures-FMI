#include<iostream>
#include <stack>
#pragma once
#pragma once
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
class SLinkedList
{
private:

	void copy(const SLinkedList& other);
	void clear();
public:
	Node* first;// tova na uprajnenie sme go pravili private, no togava ne mojem da go dostypvame, getter li trqbva da si napravim i ako da- kak
	void pushBack(Node*& first, int data);
	SLinkedList();
	SLinkedList(const SLinkedList& ohter);
	SLinkedList& operator=(const SLinkedList& other);
	~SLinkedList();

};

void pushBack(Node*& first, int data)
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
	cur->next = new Node(data);
}
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
const int MAXSIZE = 50;
using namespace std;
//
//bool downstairs(int sr, int sc, int tr, int tc, int sizeOfMatrix, int matrix[MAXSIZE][MAXSIZE], stack<int>coordinates)
//{
//	bool hasWay = true;
//	if (sr > tr || sc > tc)//ako starta e pod finala
//	{
//		hasWay = false;
//	}
//	else if (sr == tr)//ako sa na edin red
//	{
//		for (int j = sc; j < tc; j++)
//		{
//			if (matrix[sr][j] != 0)
//			{
//				hasWay = false;
//			}
//		}
//	}
//	else if (sc == tc)//ako sa na edna kolona
//	{
//		for (int i = sr; i < tr; i++)
//		{
//			if (matrix[i][sr] != 0)
//			{
//				hasWay = false;
//			}
//		}
//	}
//	else
//	{
//		int i = sr;
//		int j = sc;
//		while (i != tr || j != tc)
//		{
//			if (matrix[i][j + 1] != 0 && matrix[i + 1][j] != 0)
//			{
//				if (coordinates.size() == 0)
//				{
//					hasWay = false;
//					break;
//				}
//				if (coordinates.size() >= 2)
//				{
//					j = coordinates.top()+1;
//					coordinates.pop();
//					i = coordinates.top();
//					coordinates.pop();
//				}
//				
//				
//			}
//			else if (matrix[i + 1][j] == 0 && matrix[i][j + 1] != 0)// samo edin put nadolu
//			{
//				i++;
//			}
//			else if (matrix[i][j + 1] == 0 && matrix[j][i + 1] != 0)//samo edin put nadqsno
//			{
//				j++;
//			}
//			else// 2 putq
//			{
//				coordinates.push(i);
//				coordinates.push(j);
//				i ++;
//			}
//
//		}
//	}
//	return hasWay;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	int arr[MAXSIZE][MAXSIZE];
//	stack<int> coordinates;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> arr[i][j];
//		}
//	}
//	int sr, sc, tr, tc;
//	cin >> sr >> sc >> tr >> tc;
//	cout << boolalpha << downstairs(sr, sc, tr, tc, n, arr, coordinates);
//	while (coordinates.size() != 0)
//	{
//		cout << coordinates.top();
//		coordinates.pop();
//	}
//	return 0;
//}
//
///*
//input data
//
//4
//0 0 0 0
//1 1 1 0
//0 1 1 1
//0 0 0 0
//
//1 3 0 0  -> false
//
//4
//0 0 0 0
//1 1 1 0
//0 1 1 1
//0 0 0 0
//
//3 1  3 3 ->true
//
//4
//0 0 0 0
//0 1 1 0
//0 1 1 1
//0 0 0 0
//
//0 0  3 0  ->true
//
//4
//0 0 0 0
//0 1 1 0
//0 0 1 1
//1 0 0 0
//
//0 0  3 2   ->true
//
//4
//0 0 0 0
//0 1 1 0
//0 1 1 0
//1 0 0 0
//
//0 0  3 2  -false
//
//4
//0 0 0 1
//0 1 1 0
//0 1 1 0
//1 0 0 0
//
//0 0  3 2 ->false
//*/

//task 2
void fillGaps(Node* first)
{
	Node* curr = first;
	if (curr == nullptr)
	{
		return;
	}
	while (curr->next != nullptr)
	{
		if (curr->data != curr->next->data - 1)
		{

			Node* temp = curr;
			while (curr->data != curr->next->data - 1)
			{
				temp = new Node(curr->data + 1);
				temp->next = curr->next;
				curr->next = temp;
				curr = curr->next;
			}
		}
		curr = curr->next;
		Node* cur = first;
	}
}
void print(Node* cur)
{
	while (cur != nullptr)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
}
int main()
	{
		Node* first = nullptr;
		pushBack(first, 1);
		//pushBack(first, 2);
		pushBack(first, 3);
		pushBack(first, 4);
		pushBack(first, 7);
		pushBack(first, 11);
		fillGaps(first);
		print(first);
		return 0;
	}
	//vurtim cikul dokato curr->next ne stane nullptr
	//ako cur->next >curr+1 vurtim while ot cur+1 do next-1, v koito si pravim nodove i gi zakachkame, kato next-a na predishniq stava raven na new node, a posledniq node go zakachame za sledvashtoto chislo
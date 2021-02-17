#pragma once
struct Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node(int data, Node* left = nullptr, Node* right = nullptr) : data(data), left(left), right(right) {};
};

class BinTree
{
private:
	Node* root;
	void clear(Node*r );
	Node* copy(Node* r) const;
	void print(Node* r) const;
	void insert(Node*& r, int key, const char* path);
	void sumOfParentWithXChild(Node* r, int& sum, int x);
	void insert(Node*& r, int x);
	void sumOfBOundaries(Node* r, int& sum, int x, int y);
	void remove(Node*& r, int key);
	void finMinDiff(Node* r, int key, int& curr, int& MinDiffNode);
	int distanceBetween2(Node* r, int a, int b);
	int distanceFromSubRoot(Node* r, int x);
	void removeNodesCheck(Node* r, int k, int sum);
public:
	BinTree();
	~BinTree();
	BinTree(const BinTree& other);
	void print() const;
	void insert(int, const char* path);
	void insert(int el);
	int sumOfParentWithXChild(int x);
	int sumOfBoundaries(int x, int y);
	void remove(int key);
	int findMinDiff(int key);
	int findDistance(int a, int b);
	void removeNodesCheck(int k);
};
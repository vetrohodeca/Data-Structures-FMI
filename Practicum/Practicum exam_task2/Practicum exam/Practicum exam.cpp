#include <iostream>
#include<vector>
using namespace std;

struct Node
{
	int value;
	Node* left = nullptr;
	Node* right = nullptr;
	Node(int value)
	{
		this->value = value;
	}
	Node(int value, Node* left, Node* right)
	{
		this->value = value;
		this->left = left;
		this->right = right;
	}
};
int getDeepestLevel(Node* root, int level = 0)
{
	if (root->left == nullptr && root->right == nullptr)
	{
		return level;
	}
	if (root->right == nullptr)
	{
		return getDeepestLevel(root->left, level + 1);
	}
	if (root->left == nullptr)
	{
		return getDeepestLevel(root->right, level + 1);
	}
	return max(getDeepestLevel(root->left, level + 1), getDeepestLevel(root->right, level + 1));
}

void getValues(Node* root, vector<int>& res, int maxLevel=0,int level=0)
{
	if (root == nullptr)
	{
		return;
	}
	if (level == maxLevel)
	{
		res.push_back(root->value);
	}
	getValues(root->left, res, maxLevel, level + 1);
	getValues(root->right, res, maxLevel, level + 1);
}

vector<int> deepestValueList(Node* root)
{
	vector<int> res;
	int maxLevel = getDeepestLevel(root);
	getValues(root, res, maxLevel);
	return res;
}
int main()
{
	Node* root = new Node(1,                                      //1
		new Node(2,											//2         3
			new Node(4), new Node(5)),					// 4     5    6    7
		new Node(3,										//           2 8
			new Node(6,
				new Node(2), new Node(8)),
			new Node(7)));
	cout << getDeepestLevel(root, 0)<<endl;
	vector<int> res = deepestValueList(root);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	return 0;
}

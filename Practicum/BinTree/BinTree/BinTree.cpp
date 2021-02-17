#include"BinTree.h"

void BinTree::clear(Node*r)
{
	if (r != nullptr)
	{
		delete r->left;
		delete r->right;
		delete r;
	}
}


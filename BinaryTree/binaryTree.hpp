#include <iostream>
#include "bTree.h"

template <class T>
class binaryTree : public bTree<T>
{
	friend void printTree(const binaryTree &t, T flag);
private:
	struct Node
	{
		Node *left, *right;
		T data;
	};
};
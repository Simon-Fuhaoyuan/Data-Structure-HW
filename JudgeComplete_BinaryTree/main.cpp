#include <iostream>
#include "binaryTree.hpp"

using namespace std;

int main()
{
	binaryTree<int> tree;
	tree.createTree();
	if (tree.judgeComplete())
		cout << 'Y';
	else
		cout << 'N';
	return 0;
}
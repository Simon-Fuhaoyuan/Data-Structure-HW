#include "ChildBroBinaryTree.hpp"

using namespace std;

int main()
{
	ChildBroBinaryTree<int> tree;
	tree.createTree();
	tree.preOrder();
	tree.postOrder();
	tree.levelOrder();

	//system("pause");
	return 0;
}
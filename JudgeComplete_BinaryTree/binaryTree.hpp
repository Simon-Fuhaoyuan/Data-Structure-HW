#include <iostream>
#include "sLinkList.hpp"
#include "linkQueue.hpp"
using namespace std;

template <class T>
struct Node
{
	Node *left, *right;
	T data;

	Node() :left(NULL), right(NULL) {}
	Node(T item, Node *left = NULL, Node *right = NULL) : data(item), left(left), right(right) {}
	~Node() {}
};

template <class T>
class binaryTree
{
private:
	Node<T> *root; // root node of the binary tree
	sLinkList<Node<T>*> rootList;

public:
	binaryTree() : root(NULL){}
	~binaryTree();
	void clear();
	bool isEmpty() const;
	void createTree();
	bool judgeComplete();

private:
	Node<T> *find(T x, Node<T> *t) const; // recursive function to find the node with data x
	Node<T> *find(T x);
	void clear(Node<T> *&t); // recursive function to delete nodes
	void createNode(Node<T> *target, Node<T> *lchild, Node<T> *rchild);
	bool judgeComplete(Node<T> *current);
};

template<class T>
inline Node<T> * binaryTree<T>::find(T x, Node<T> * t) const
{
	if (t == NULL) return NULL;

	if (t->data == x) return t;

	Node<T> *tmp;
	tmp = find(x, t->left);
	if (tmp != NULL) return tmp;

	return find(x, t->right);
}

template<class T>
inline Node<T>* binaryTree<T>::find(T x)
{
	for (int i = 0; i < rootList.length(); ++i)
	{
		Node<T> *currentRoot = rootList.visit(i);
		if (currentRoot->data == x)
		{
			rootList.remove(i);
			return currentRoot;
		}
		Node<T> *tmp = find(x, currentRoot);
		if (tmp != NULL)
			return tmp;
	}
	return NULL;
}

template<class T>
inline void binaryTree<T>::clear(Node<T> *& t)
{
	if (t == NULL) return;

	clear(t->left);
	clear(t->right);
	delete t;
	t = NULL;
}

template<class T>
inline binaryTree<T>::~binaryTree()
{
	clear();
}

template<class T>
inline void binaryTree<T>::clear()
{
	clear(root);
}

template<class T>
inline bool binaryTree<T>::isEmpty() const
{
	return root == NULL;
}

template<class T>
inline void binaryTree<T>::createNode(Node<T> *target, Node<T> *lchild, Node<T> *rchild)
{
	target->left = lchild;
	target->right = rchild;
}

template<class T>
inline void binaryTree<T>::createTree()
{
	int N = 0;
	cin >> N;
	T lIndex, rIndex;
	Node<T> *lchild, *rchild, *target;
	Node<T> *checkLchild, *checkRchild;

	for (int i = 0; i < N; ++i)
	{
		cin >> lIndex >> rIndex;
		// deal with left child
		if (lIndex == 0)
			lchild = NULL;
		else
		{
			checkLchild = find(lIndex);
			if (checkLchild != NULL)
				lchild = checkLchild;
			else
				lchild = new Node<T>(lIndex);
		}

		// deal with right child
		if (rIndex == 0)
			rchild = NULL;
		else
		{
			checkRchild = find(rIndex);
			if (checkRchild != NULL)
				rchild = checkRchild;
			else
				rchild = new Node<T>(rIndex);
		}

		// deal with this node
		target = find(i + 1);
		if (target == NULL)
		{
			target = new Node<T>(i + 1, lchild, rchild);
			rootList.insert(rootList.length(), target);
		}
		else
			createNode(target, lchild, rchild);
	}

	root = rootList.visit(0);
}

template<class T>
inline bool binaryTree<T>::judgeComplete()
{
	linkQueue<Node<T>*> treeQueue;
	treeQueue.enQueue(root);
	Node<T> *tmp;

	while(!treeQueue.isEmpty())
	{
		tmp = treeQueue.deQueue();
		if (tmp == NULL) break;

		treeQueue.enQueue(tmp->left);
		treeQueue.enQueue(tmp->right);
	}

	while(!treeQueue.isEmpty())
	{
		tmp = treeQueue.deQueue();
		if (tmp != NULL) return false;
	}
	return true;
}
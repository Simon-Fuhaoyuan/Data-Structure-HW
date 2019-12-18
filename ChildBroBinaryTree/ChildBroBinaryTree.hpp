#include <iostream>
#include "LinkStack.hpp"
#include "linkQueue.hpp"
using namespace std;

template <class T>
struct Node
{
	int index;
	T data;
	Node *child, *bro;
	bool visited;

	Node() : child(NULL), bro(NULL) {}
	Node(int n) : index(n), child(NULL), bro(NULL), visited(false) {}
	~Node() {}
};

template <class T>
class ChildBroBinaryTree
{
private:
	Node<T> **root;
	int maxSize;
	int currentSize;

public:
	ChildBroBinaryTree() : root(new Node<T>*[10]), maxSize(10), currentSize(0) {}
	~ChildBroBinaryTree();
	void createTree();
	void preOrder();
	void postOrder();
	void levelOrder();

private:
	Node<T> *find(int idx, bool &flag, int &rootIdx);
	Node<T> *find(Node<T> *current, int idx);
	void createNode(Node<T> *target, Node<T> *child, Node<T> *bro, T data);
	void clear(Node<T> *current);
	void postOrder(Node<T> * current);
	void doubleSpace();
	void cutRoot(int idx);
};

template<class T>
inline Node<T>* ChildBroBinaryTree<T>::find(int idx, bool &flag, int &rootIdx)
{
	for (int i = 0; i < currentSize; ++i)
	{
		Node<T> *currentRoot = root[i];
		if (!currentRoot->visited && currentRoot->index == idx)
		{
			flag = true;
			rootIdx = i;
			currentRoot->visited = true;
			return currentRoot;
		}
		Node<T> *tmp = find(currentRoot, idx);
		if (tmp != NULL) return tmp;
	}
	return NULL;
}

template<class T>
inline Node<T>* ChildBroBinaryTree<T>::find(Node<T>* current, int idx)
// Find recursively the target index
{
	if (current == NULL) return NULL;
	if (!current->visited && current->index == idx) 
	{
		current->visited = true;
		return current;
	}
	Node<T> *tmp = find(current->bro, idx);
	if (tmp != NULL)
		return tmp;

	return find(current->child, idx);
}

template<class T>
inline void ChildBroBinaryTree<T>::createNode(Node<T>* target, Node<T>* child, Node<T>* bro, T data)
// Fill in the info of target node
{
	target->bro = bro;
	target->child = child;
	target->data = data;
}

template<class T>
inline void ChildBroBinaryTree<T>::clear(Node<T>* current)
// return the address to OS recursively
{
	if (current == NULL) return;
	clear(current->bro);
	clear(current->child);
	delete current;
}

template<class T>
inline ChildBroBinaryTree<T>::~ChildBroBinaryTree()
{
	clear(root[0]);
	delete[]root;
}

template<class T>
inline void ChildBroBinaryTree<T>::doubleSpace()
{
	Node<T> **tmp = root;
	root = new Node<T>*[maxSize * 2];
	for (int i = 0; i < currentSize; ++i)
		root[i] = tmp[i];
	delete[]tmp;
	maxSize *= 2;
}

template<class T>
inline void ChildBroBinaryTree<T>::cutRoot(int idx)
{
	root[idx] = NULL;
	for (int i = idx; i < currentSize - 1; ++i)
		root[i] = root[i + 1];
	currentSize--;
}

template<class T>
inline void ChildBroBinaryTree<T>::createTree()
// input process to create a tree
{
	// input stage
	int N = 0;
	cin >> N;
	int childIdx, broIdx;
	T data;
	Node<T> *child, *bro;
	
	for (int i = 0; i < N; ++i)
	{
		bool flag = false;
		bool isRoot = false;
		int rootIdx = 0;
		bool ignore;
		int ign;
		cin >> childIdx >> broIdx >> data;
		// find the target node in the tree
		Node<T> *target = find(i + 1, ignore, ign);
		// check if the child node or brother node has already existed!!

		if (childIdx == 0)
			child = NULL;
		else
		{
			Node<T> *checkChild = find(childIdx, isRoot, rootIdx);
			if (isRoot)
				cutRoot(rootIdx);
			if (checkChild == NULL) child = new Node<T>(childIdx);
			else child = checkChild;
		}
		isRoot = false;
		
		if (broIdx == 0)
			bro = NULL;
		else
		{
			Node<T> *checkBro = find(broIdx, isRoot, rootIdx);
			if (isRoot)
				cutRoot(rootIdx);
			if (checkBro == NULL) bro = new Node<T>(broIdx);
			else bro = checkBro;
		}

		if (target == NULL)
		{
			target = new Node<T>(i + 1);
			flag = true;
		}
			
		// fill the node with input info
		createNode(target, child, bro, data);

		if (flag)
		{
			if (currentSize == maxSize) doubleSpace();
			root[currentSize++] = target;
		}
	}
}

template<class T>
inline void ChildBroBinaryTree<T>::preOrder()
{
	linkStack<Node<T>*> nodeStack;
	nodeStack.push(root[0]);
	Node<T> *tmp;

	while (!nodeStack.isEmpty())
	{
		tmp = nodeStack.pop();
		if (tmp == NULL) continue;
		nodeStack.push(tmp->bro);
		nodeStack.push(tmp->child);
		cout << tmp->data << ' ';
	}
	cout << endl;
}

template<class T>
inline void ChildBroBinaryTree<T>::postOrder(Node<T>* current)
{
	if (current == NULL) return;
	postOrder(current->child);
	cout << current->data << ' ';
	postOrder(current->bro);
}

template<class T>
inline void ChildBroBinaryTree<T>::postOrder()
{
	postOrder(root[0]);
	cout << endl;
}

template<class T>
inline void ChildBroBinaryTree<T>::levelOrder()
{
	linkQueue<Node<T>*> nodeQueue;
	nodeQueue.enQueue(root[0]);
	Node<T> *tmp;

	while (!nodeQueue.isEmpty())
	{
		tmp = nodeQueue.deQueue();
		if (tmp == NULL) continue;
		while (tmp != NULL)
		{
			cout << tmp->data << ' ';
			nodeQueue.enQueue(tmp->child);
			tmp = tmp->bro;
		}
	}
	cout << endl;
}
#include "Stack.h"
#include <iostream>

using namespace std;

template <class elemType>
struct stackNode
{
	elemType data;
	stackNode *next;
	stackNode(const elemType &x, stackNode *N = NULL)
	{
		data = x;
		next = N;
	}
	stackNode() :next(NULL){}
	~stackNode() {}
};

template <class elemType>
class linkStack :public stack<elemType>
{
private:
	stackNode<elemType> *top_p;

public:
	linkStack();
	~linkStack();
	bool isEmpty() const;
	void push(const elemType &x);
	elemType pop();
	elemType top() const;
};

template<class elemType>
inline linkStack<elemType>::linkStack()
{
	top_p = NULL;
}

template<class elemType>
inline linkStack<elemType>::~linkStack()
{
	stackNode<elemType> *tmp;
	while (top_p != NULL)
	{
		tmp = top_p;
		top_p = top_p->next;
		delete tmp;
	}
}

template<class elemType>
inline bool linkStack<elemType>::isEmpty() const
{
	return top_p == NULL;
}

template<class elemType>
inline void linkStack<elemType>::push(const elemType & x)
{
	stackNode<elemType> *tmp = top_p;
	top_p = new stackNode<elemType>(x, tmp);
}

template<class elemType>
inline elemType linkStack<elemType>::pop()
{
	stackNode<elemType> *tmp = top_p;
	elemType x = tmp->data;
	top_p = top_p->next;
	delete tmp;
	return x;
}

template<class elemType>
inline elemType linkStack<elemType>::top() const
{
	return top_p->data;
}
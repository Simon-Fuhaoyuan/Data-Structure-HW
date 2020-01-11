#pragma once
#include "List.h"
#include <iostream>

using namespace std;

template <class elemType>
struct node
{
	elemType data;
	node *next;
	node(const elemType &x, node *n = NULL) { data = x; next = n; }
	node() :next(NULL) {}
	~node() {}
};

template <class elemType>
class sLinkList : public List<elemType>
{
private:
	node<elemType> *head;
	int currentLength;
	node<elemType> *move(int i) const;
public:
	sLinkList();
	~sLinkList() { clear(); delete head; }
	void clear();
	int length() const { return currentLength; }
	void insert(int i, const elemType &x);
	void remove(int i);
	int search(const elemType &x) const;
	elemType visit(int i) const;
	void traverse() const;
};

template<class elemType>
sLinkList<elemType>::sLinkList()
{
	head = new node<elemType>;
	currentLength = 0;
}

template<class elemType>
node<elemType> *sLinkList<elemType>::move(int i) const
{
	node<elemType> *p = head;
	while (i >= 0)
	{
		p = p->next;
		i--;
	}
	return p;
}

template<class elemType>
void sLinkList<elemType>::clear()
{
	node<elemType> *p = head->next;
	node<elemType> *q;
	while (p != NULL)
	{
		q = p->next;
		delete p;
		p = q;
	}
	head->next = NULL;
	currentLength = 0;
}

template<class elemType>
void sLinkList<elemType>::insert(int i, const elemType & x)
{
	if (i < 0 || i >currentLength) 
		throw OutOfBound();
	node<elemType> *p = move(i - 1);
	node<elemType> *newEle = new node<elemType>(x, p->next);
	p->next = newEle;
	currentLength++;
}

template<class elemType>
void sLinkList<elemType>::remove(int i)
{
	if (i < 0 || i >= currentLength)
		throw OutOfBound();
	node<elemType> *p = move(i - 1);
	node<elemType> *dlp = p->next;
	p->next = dlp->next;
	delete dlp;
	currentLength--;
}

template<class elemType>
int sLinkList<elemType>::search(const elemType & x) const
{
	node<elemType> *p = head->next;
	int i = 0;
	while (p != NULL && p->data != x)
	{
		p = p->next;
		i++;
	}
	if (p == NULL) return -1;
	else return i;
}

template<class elemType>
elemType sLinkList<elemType>::visit(int i) const
{
	if (i < 0 || i >= currentLength)
		throw OutOfBound();
	return move(i)->data;
}

template<class elemType>
void sLinkList<elemType>::traverse() const
{
	node<elemType> *p = head->next;
	cout << endl;
	while (p != NULL)
	{
		cout << p->data << ' ';
		p = p->next;
	}
}
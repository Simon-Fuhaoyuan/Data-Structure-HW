#include "queue.h"
#include <iostream>

using namespace std;

template <class elemType>
struct queueNode
{
	elemType data;
	queueNode *next;
	queueNode(const elemType &x, queueNode *N = NULL)
	{
		data = x;
		next = N;
	}
	queueNode() :next(NULL){}
	~queueNode() {}
};

template <class elemType>
class linkQueue : public queue<elemType>
{
private:
	queueNode<elemType> *front;
	queueNode<elemType> *rear;

public:
	linkQueue();
	~linkQueue();
	bool isEmpty();
	void enQueue(const elemType &x);
	elemType deQueue();
	elemType getHead();
};

template<class elemType>
inline linkQueue<elemType>::linkQueue()
{
	front = rear = NULL;
}

template<class elemType>
inline linkQueue<elemType>::~linkQueue()
{
	queueNode<elemType> *tmp = front;
	while (front != NULL)
	{
		tmp = front;
		front = front->next;
		delete tmp;
	}
}

template<class elemType>
inline bool linkQueue<elemType>::isEmpty()
{
	return front == NULL;
}

template<class elemType>
inline void linkQueue<elemType>::enQueue(const elemType & x)
{
	if (isEmpty())
		front = rear = new queueNode<elemType>(x, NULL);
	else
	{
		rear->next = new queueNode<elemType>(x, NULL);
		rear = rear->next;
	}
}

template<class elemType>
inline elemType linkQueue<elemType>::deQueue()
{
	if (isEmpty())
	{
		cout << "The queue is empty!\n";
		exit(-1);
	}
	queueNode<elemType> *tmp = front;
	elemType ans = front->data;
	front = front->next;
	if (front == NULL)
		rear = NULL;
	delete tmp;
	return ans;
}

template<class elemType>
inline elemType linkQueue<elemType>::getHead()
{
	if (isEmpty())
	{
		cout << "The queue is empty!\n";
		exit(-1);
	}

	return front->data;
}
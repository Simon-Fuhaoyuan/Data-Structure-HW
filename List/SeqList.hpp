#pragma once

#include "List.h"
#include <iostream>

using namespace std;

template <class elemType>
class SeqList : public List<elemType>
{
private:
	elemType *data;
	int currentLength;
	int maxSize;
	void doubleSpace();
public:
	SeqList(int initSize = 10);
	~SeqList() { delete[]data; }
	void clear() { currentLength = 0; }
	int length() const { return currentLength; }
	void insert(int i, const elemType &x);
	void remove(int i);
	int search(const elemType &x) const;
	elemType visit(int i) const;
	void traverse() const;
};

template<class elemType>
SeqList<elemType>::SeqList(int initSize)
{
	if (initSize <= 0)
		throw IlleglalSize();
	data = new elemType[initSize];
	maxSize = initSize;
	currentLength = 0;
}

template<class elemType>
void SeqList<elemType>::insert(int i, const elemType & x)
{
	if (i < 0 || i > currentLength)
		throw OutOfBound();
	if (currentLength == maxSize) doubleSpace();
	for (int j = currentLength; j > i; --j)
		data[j] = data[j - 1];
	data[i] = x;
	currentLength++;
}

template<class elemType>
void SeqList<elemType>::remove(int i)
{
	if (i < 0 || i >= currentLength)
		throw OutOfBound();
	for (int j = i; j < currentLength - 1; ++j)
		data[j] = data[j + 1];
	currentLength--;
}

template<class elemType>
int SeqList<elemType>::search(const elemType & x) const
{
	int i = 0;
	for (; i < currentLength && data[i] != x; ++i);
	if (currentLength == i) return -1; //no such element
	else return i;
}

template<class elemType>
elemType SeqList<elemType>::visit(int i) const
{
	if (i < 0 || i >= currentLength) throw OutOfBound();
	return data[i];
}

template<class elemType>
void SeqList<elemType>::traverse() const
{
	cout << endl;
	for (int i = 0; i < currentLength; ++i)
		cout << data[i] << ' ';
}

template<class elemType>
void SeqList<elemType>::doubleSpace()
{
	maxSize *= 2;
	elemType *previous = data;
	data = new elemType[maxSize];
	for (int i = 0; i < currentLength; ++i)
		data[i] = previous[i];
	delete[]previous;
}
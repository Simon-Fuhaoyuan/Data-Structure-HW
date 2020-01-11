#pragma once

#include "List.h"

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

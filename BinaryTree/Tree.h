#pragma once
template<class T>
class Tree
{
public:
	virtual void clear() = 0;
	virtual bool isEmpty() = 0;
	virtual T root(T flag) const = 0; // return flag when no root
	virtual T parent(T x, T flag) const = 0; // return flag when x doesn't exist or x is root(no parent)
	virtual void remove(T x, int i) = 0; // remove the ith subtree of node x
	virtual void traverse() const = 0;
};


#pragma once
#include <exception>
using namespace std;
class OutOfBound : public exception
{
public:
	virtual const char *what() const throw()
	{
		return "Out of bound!\n";
	}
};

class IlleglalSize : public exception
{
public:
	virtual const char *what() const throw()
	{
		return "Illegale size!\n";
	}
};

template <class elemType>
class List
{
public:
	virtual void clear() = 0;
	virtual int length() const = 0;
	virtual void insert(int i, const elemType &x) = 0;
	virtual void remove(int i) = 0;
	virtual int search(const elemType &x) const = 0;
	virtual elemType visit(int i) const = 0;
	virtual void traverse() const = 0;
	virtual ~List() {};
};
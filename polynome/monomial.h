#pragma once
#include <iostream>
using namespace std;

class monomial
{
private:
	double coef;
	int exp;
public:
	monomial() :coef(0), exp(0) {}
	monomial(double coef, int exp) :coef(coef), exp(exp) {}
	~monomial() {}
	double get_coef() { return coef; }
	double get_exp() { return exp; }
	bool operator==(const monomial &mono);
	bool operator!=(const monomial &mono);
	monomial operator*(const monomial &mono);
	monomial operator+(const monomial &mono);
	bool operator<(const monomial &mono); // note that we only compare the value of exp here
	friend ostream &operator<<(ostream & os, monomial & mono);
};
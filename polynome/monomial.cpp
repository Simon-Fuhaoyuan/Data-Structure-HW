#include "monomial.h"
#include <iostream>
using namespace std;

bool monomial::operator==(const monomial & mono)
{
	if (this->coef == mono.coef && this->exp == mono.exp) return true;
	return false;
}

bool monomial::operator!=(const monomial & mono)
{
	if (this->coef != mono.coef || this->exp != mono.exp) return true;
	return false;
}

monomial monomial::operator*(const monomial & mono)
{
	double new_coef = this->coef * mono.coef;
	int new_exp = this->exp + mono.exp;
	return monomial(new_coef, new_exp);
}

monomial monomial::operator+(const monomial & mono)
{
	if (this->exp == mono.exp)
		return monomial(this->coef + mono.coef, this->exp);
	else
		return *this;
}

bool monomial::operator<(const monomial & mono)
{
	if (this->exp < mono.exp)
		return true;
	return false;
}

ostream & operator<<(ostream & os, monomial & mono)
{
	if (mono.get_coef() != 0)
		os << mono.get_coef() << ' ' << mono.get_exp() << ' ';
	return os;
}
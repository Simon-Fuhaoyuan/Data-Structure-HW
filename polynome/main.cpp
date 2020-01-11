#include <iostream>
#include <exception>
#include "List.h"
#include "sLinkList.hpp"
#include "monomial.h"

using namespace std;

int main()
{
	sLinkList<monomial> poly1, poly2;
	int cnt_poly1, cnt_poly2;
	double coef;
	int exp;
	// input stage
	cin >> cnt_poly1 >> cnt_poly2;
	// actually, this can be done without the count of poly1 and poly2
	while (cin >> coef && cin >> exp)
	{
		monomial tem(coef, exp);
		poly1.insert(poly1.length(), tem);
		if (cin.get() == '\n') break;
	}
	while (cin >> coef && cin >> exp)
	{
		monomial tem(coef, exp);
		poly2.insert(poly2.length(), tem);
		if (cin.get() == '\n') break;
	}
	// calculate stage
	for (int i = 0; i < poly1.length(); ++i)
		for (int j = 0; j < poly2.length(); ++j)
		{
			if (poly2.visit(j).get_exp() > poly1.visit(i).get_exp())
			{
				if (j == poly2.length() - 1)
					// if the exp of a monomial in poly1 is smaller than any of those in poly2
					// insert this monomial at the end of poly2
				{
					poly2.insert(j + 1, poly1.visit(i));
					break;
				}
				continue;
			}
			else if (poly2.visit(j).get_exp() == poly1.visit(i).get_exp())
			{
				monomial temp(poly1.visit(i) + poly2.visit(j));
				// update polynome2 with a new monomial
				poly2.remove(j);
				poly2.insert(j, temp);
				break;
			}
			else
			{
				poly2.insert(j, poly1.visit(i));
				break;
			}
		}
	// check stage
	bool empty_flag = true; // check whether the polynome is empty
	for (int i = 0; i < poly2.length(); ++i)
		if (poly2.visit(i).get_coef() != 0)
		{
			empty_flag = false;
			break;
		}
	// output stage
	if (!empty_flag)
		poly2.traverse();
	else
		cout << "0 0";
	//system("pause");
	return 0;
}
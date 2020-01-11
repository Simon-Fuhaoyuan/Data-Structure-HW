#include "SeqList.hpp"
#include "sLinkList.hpp"
#include <iostream>

using namespace std;

int main()
{
	try
	{
		SeqList<int> list(-2);
		list.insert(0, 1);
		list.insert(1, 5);
		list.insert(2, 8);
		list.traverse();
		cout << endl << list.length() << endl;
		cout << 10 << ": " << list.search(10) << endl;
		cout << 5 << ": " << list.search(5) << endl;

		list.remove(1);
		cout << "REMOVE 1" << endl;
		cout << list.length() << endl;
		cout << 5 << ": " << list.search(5) << endl;
		cout << 8 << ": " << list.search(8) << endl;
		cout << list.visit(1) << endl;

		list.clear();
		list.traverse();
		cout << "=========================" << endl;

		sLinkList<int> llist;
		llist.insert(0, 1);
		llist.insert(1, 5);
		llist.insert(2, 8);
		llist.traverse();
		cout << endl << llist.length() << endl;
		cout << 10 << ": " << llist.search(10) << endl;
		cout << 5 << ": " << llist.search(5) << endl;

		llist.remove(1);
		cout << "REMOVE 1" << endl;
		cout << llist.length() << endl;
		cout << 5 << ": " << llist.search(5) << endl;
		cout << 8 << ": " << llist.search(8) << endl;
		cout << llist.visit(1) << endl;

		llist.clear();
		llist.traverse();
	}
	catch (exception &e)
	{
		cout << e.what();
	}

	system("pause");
	return 0;
}
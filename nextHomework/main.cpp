#include <iostream>

using namespace std;

int main()
{
	// This question uses the logic of a circulate queue.
	// Every time TA changes a question, assume he gives q th question this time,
	// he will give (q + m) % n next time.
	// Repeatedly, this will easily give a correct answer without using any datastructure.

	int number, change, power, target;
	cin >> number >> change >> power >> target;

	// The times of giving questions may be large, we only calculate (times % n),
	// for example, 100 times is equivalent to 1 time if n == 3
	int mod = 1;
	for (int i = 0; i < power; ++i)
	{
		mod = (mod * 10) % number;
	}

	// Again, we only calculate (time * m % n), this is similar to last stage
	mod *= change;
	mod = mod % number;

	// Finally, we get which question is assigned by the target TA
	target = (target + mod) % number;
	cout << target;

	system("pause");
	return 0;
}
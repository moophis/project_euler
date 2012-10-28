/*
 * The following iterative sequence is defined for the set of positive integers:

	n -> n/2 (n is even)
	n -> 3n + 1 (n is odd)

	Using the rule above and starting with 13, we generate the following sequence:

	13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1

	It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
	Although it has not been proved yet (Collatz Problem),
	it is thought that all starting numbers finish at 1.
	Which starting number, under one million, produces the longest chain?

	NOTE: Once the chain starts the terms are allowed to go above one million.
 */
#include <iostream>
using namespace std;

int findChain(unsigned long n)
//use divide-and-conquer paradigm
{
    if (n < 1) return -1;
	if (n == 1) return 1;
	else
	{
		unsigned long next;
		next = (n % 2 == 0) ? (n / 2) : (3 * n + 1);
		return findChain(next) + 1;
	}
}

int _findChain(unsigned long n)
//do not use divide-and-conquer paradigm
{
	int counter = 0;
	while (n > 1)
	{
		counter++;
		n = (n % 2 == 0) ? (n / 2) : (3 * n + 1);
	}
	return ++counter;
}
int main()
{
	int val = 0, max = 0;
	for (int i = 1; i < 1000000; i++)
    {
        int t = findChain(i);
        if (t > max)
        {
            max = t;
            val = i;
        }
    }
	cout << val << endl;
	cout << max << endl;
	return 0;
}

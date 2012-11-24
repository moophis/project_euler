/*
 A permutation is an ordered arrangement of objects.
 For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
 If all of the permutations are listed numerically or alphabetically,
 we call it lexicographic order.
 The lexicographic permutations of 0, 1 and 2 are:

 012   021   102   120   201   210

 What is the millionth lexicographic permutation of the digits
 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 */

#include <iostream>
#include <cassert>

using namespace std;

int digits[10]; // digit[0] := least significant bit

int factorial(int n)
{
	assert(n >= 0);
	if (n == 1 || n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

void pos_lexper(long pos)
{
	assert(pos < factorial(10) && pos > 0);

	long counter  = 0, tmp;
	bool used[10] = {false};

	for (int i = 9; i >= 0; i--) {	// choose bit index
		for (int j = 0; j < 10; j++) {	// choose what number in that bit
			if (used[j])	// this number has been used
				continue;
			digits[i] = j;

			if ((tmp = counter + factorial(i)) >= pos) { // be careful in here!
			    used[j] = true;
				break;
			}
			else
				counter = tmp;
		}
	}
}

int main()
{
    pos_lexper(1000000l);
	for (int i = 9; i >=0; i--)
		cout << digits[i];

	return 0;
}

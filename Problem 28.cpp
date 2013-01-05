/*
 * Starting with the number 1 and moving to the right in
 * a clockwise direction a 5 by 5 spiral is formed as follows:

	21 22 23 24 25
	20  7  8  9 10
	19  6  1  2 11
	18  5  4  3 12
	17 16 15 14 13

 * It can be verified that the sum of the numbers on the diagonals is 101.
 * What is the sum of the numbers on the diagonals in a 1001 by 1001
 * spiral formed in the same way?
 */
#include <iostream>

using namespace std;

int diagsum(int size)
{
	int num_now  = 1;
	int half, last_half = 0;
	int sum = 1;

	// input ought to be odd
	if ( size % 2 == 0 || size < 0) {
		cerr << "Size input should be positive odd number!" << endl;
		return -1;
	}

	if ( size == 1 )
		return sum;

	for (int i = 3; i <= size; i = i + 2) {
		half = i / 2;

		// go right for 1 step
		num_now++;
		// go to southeast
		num_now += last_half + half;
		sum += num_now;
		// go to southwest
		num_now += half * 2;
		sum += num_now;
		// go to northwest
		num_now += half * 2;
		sum += num_now;
		// go to northeast
		num_now += half * 2;
		sum += num_now;

		last_half = half;
	}

	return sum;
}

int main()
{
	cout << diagsum(1001) << endl;
	return 0;
}

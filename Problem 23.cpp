/*
  A perfect number is a number for which the sum of its proper divisors
  is exactly equal to the number. For example, the sum of the proper divisors
  of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

  A number n is called deficient if the sum of its proper divisors is less than n and
  it is called abundant if this sum exceeds n.

  As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number
  that can be written as the sum of two abundant numbers is 24. By mathematical analysis,
  it can be shown that all integers greater than 28123 can be written as the sum of
  two abundant numbers. However, this upper limit cannot be reduced any further
  by analysis even though it is known that the greatest number that cannot be expressed
  as the sum of two abundant numbers is less than this limit.

  Find the sum of all the positive integers which cannot be written
  as the sum of two abundant numbers.
 */

#include <iostream>
#include <vector>
#define MAX_NUM 28123

using namespace std;

enum {DEFICIENT = -1, PERFECT, ABUNDANT};
bool numtab[MAX_NUM + 1];

/* determine whether a number is a perfect, deficient, or abundant number  */
int int_kind(int num)
{
	int counter = 0;

	for (int i = 1; i <= num / 2; i++) {
		if (num % i == 0)
			counter += i;
		else
			continue;
	}

	if (counter < num)
		return -1;	// deficient
	else if (counter > num)
		return 1;	// abundant
	else
		return 0;	// perfect
}

/*
 * Find all the positive integers which cannot be written
 * as the sum of two abundant numbers.
 */
void find_num()
{
	int sum;
	vector<int> abundant;

	for (int i = 1; i < MAX_NUM; i++)
		if (int_kind(i) == ABUNDANT) {
			abundant.push_back(i);
		}

	for (int i = 0; i <= abundant.size(); i++) {
		for (int j = i; j <= abundant.size(); j++) {
			if ((sum = abundant[i] + abundant[j]) > MAX_NUM)
				break;
			numtab[sum] = true;
		}
	}
}

int main()
{
	unsigned int total = 0;

	for (int i = 1; i <= MAX_NUM; i++)
		numtab[i] = false;

	find_num();
	for (int i = 1; i <= MAX_NUM; i++) {
		if (!numtab[i])
			total += i;
	}
	cout << total << endl;

	return 0;
}



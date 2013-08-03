/** 
 * Surprisingly there are only three numbers that can be written 
   as the sum of fourth powers of their digits:

	1634 = 1^4 + 6^4 + 3^4 + 4^4
	8208 = 8^4 + 2^4 + 0^4 + 8^4
	9474 = 9^4 + 4^4 + 7^4 + 4^4
	As 1 = 1^4 is not a sum it is not included.

	The sum of these numbers is 1634 + 8208 + 9474 = 19316.

 * Find the sum of all the numbers that can be written as the 
 * sum of fifth powers of their digits.
 */
#include <iostream>

using namespace std;

int do_dsum(unsigned n)
{
	int sum = 0, each, pow = 1;
	
	while (n > 0) {
		each = n % 10;
		for (int i = 0; i < 5; i++) {
			pow = pow * each;
		}
		sum += pow;
		n = n / 10;
		pow = 1;
	}
	
	return sum;
}

long five_pows_sum()
{
	long total = 0;
	
	for (int i = 2; i < 354294; i++) { 
		// 354294 = 6 * 9 ^ 5
		if (i == do_dsum(i)) {
			cout << "catch one: " << i << endl;
			total += i;
		}
	}
	
	return total;
}

int main()
{
	cout << five_pows_sum() << endl;
	//cout << do_dsum(1234) << endl;
	return 0;
}
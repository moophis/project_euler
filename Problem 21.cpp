/*
 Let d(n) be defined as the sum of proper divisors of n 
 (numbers less than n which divide evenly into n).
 If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and
 each of a and b are called amicable numbers.

 For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110;
 therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

 Evaluate the sum of all the amicable numbers under 10000.
*/

#include <iostream>

using namespace std;

int SumOfDivisors(int n)
{
	int counter = 0;
	for (int i = 1; i <= n/2; i++) {
		if (n % i == 0) 
			counter += i;
	} 
	
	return counter;
}

bool AreAmicable(int n1)
{
	int n2 = SumOfDivisors(n1);
	return n1 != n2 && n1 == SumOfDivisors(n2);
}

int main()
{
	int sum = 0;
	for (int i = 1; i < 10000; i++) {
		if (AreAmicable(i))
			sum += i;
	}
	
	cout << "the sum is " << sum << endl;
	
	return 0;
}

/*
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
 * we can see that the 6th prime is 13.
 * What is the 10 001st prime number?
 */
#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int n)
{
	for (int i = 2; i < n; i++)
		if (n % i == 0) return false;
	return true;
}

int main()
{
	int j,counter = 0;

	for (j = 2; counter < 10001; j++)
		if (isPrime(j)) counter++;
	cout << --j << endl;
	return 0;
}

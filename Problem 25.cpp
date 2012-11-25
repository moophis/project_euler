/*
 The Fibonacci sequence is defined by the recurrence relation:

 Fn = Fn1 + Fn2, where F1 = 1 and F2 = 1.
 Hence the first 12 terms will be:

	F1 = 1
	F2 = 1
	F3 = 2
	F4 = 3
	F5 = 5
	F6 = 8
	F7 = 13
	F8 = 21
	F9 = 34
	F10 = 55
	F11 = 89
	F12 = 144

 The 12th term, F12, is the first term to contain three digits.
 What is the first term in the Fibonacci sequence to contain 1000 digits?
 */

#include <iostream>

using namespace std;

int num1[1000] = {0}, num2[1000] = {0};

/* add two large numbers contained in arrays */
void array_add(int a[], int b[])
{
	int carry = 0, bitsum = 0;

	for (int i = 0; i < 1000; i++) {
		bitsum = a[i] + b[i] + carry;
		a[i]   = bitsum % 10;
		carry  = bitsum / 10;
	}
}

long find_first_1000()
{
	long n = 2;

	num1[0] = num2[0] = 1; // initial case: F1, F2
	while (num1[999] == 0 && num2[999] == 0) {
		++n;
		if (n % 2 != 0)	   // num1 = num1 + num2
			array_add(num1, num2);
		else 			   // num2 = num2 + num1
			array_add(num2, num1);
	}

	return n;
}

int main()
{
	cout << find_first_1000() << endl;
	return 0;
}

/*
 * If the numbers 1 to 5 are written out in words:
 * one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 * If all the numbers from 1 to 1000 (one thousand) inclusive
 * were written out in words, how many letters would be used?
 * NOTE: Do not count spaces or hyphens.
 * For example, 342 (three hundred and forty-two) contains 23 letters
 * and 115 (one hundred and fifteen) contains 20 letters.
 * The use of "and" when writing out numbers is in compliance with British usage.
 */
//21124
#include <iostream>
#define HUNDRED 7
#define THOUSAND 11
#define AND 3
using namespace std;
int main()
{
	int ans = 0;
	int unit, tens, below100;
	/* 1 to 9 */
	unit = 3 + 3 + 5 + 4 + 4 + 3 + 5 + 5 + 4;
	ans += unit;

	/* 10 to 19 */
	tens = 3 + 6 + 6 + 8 + 8 + 7 + 7 + 9 + 8 + 8;
	ans += tens;

	/* 20 to 99 */
	below100 = (6 + 6 + 5 + 5 + 5 + 7 + 6 + 6) * 10 + unit * 8;
	ans += below100;

	/* 100 to 999 */
	ans += unit * 100 + HUNDRED * 100 * 9 + AND * 99 * 9 + (unit + tens + below100) * 9;
	/* 1000 */
	ans += THOUSAND;

	cout << ans << endl;
	return 0;
}

/*
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 *              a^2 + b^2 = c^2
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */
#include <iostream>
using namespace std;

int main()
{
	int a,b,c;
	for (c = 335; c < 500; c++)  //a + b > c, a < b < c
	{
		for (a = 1; ; a++)
		{
			b = 1000 - c - a;
			if (a >= b) break;
			if (b >= c) continue;
			else
			{
				int a1 = a * a, b1 = b * b, c1 = c * c;
				if (c1 == a1 + b1)
					cout << "a = " << a <<" "
						 << "b = " << b <<" "
						 << "c = " << c << endl
						 << "abc = " << a * b * c << endl;
			}
		}
	}
	return 0;
}

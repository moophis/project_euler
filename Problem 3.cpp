/*
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 */

#include <iostream>
#include <math.h>
using namespace std;
long long target = 600851475143;   //the number is extremely big

int main()
{
	long long ans = 2;
	for (long long i = 2; target > 1; i++)
	{
        if (target % i == 0)
        {
            target = target / i;
            ans = i;
            while (target % i == 0)
                target = target / i;    //divide the target with the same divisor
        }                               //until the target cannot be divided by it
	}
	cout << ans << endl;
	return 0;
}


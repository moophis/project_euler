/*
 * Find the sum of all the primes below two million.
 */
#include <iostream>
#include <math.h>
#include <time.h>
#define NUM 2000000

using namespace std;

bool isPrime(int n)
{
	if (n == 1) return false;
	else if (n < 4) return true;
	else if (n % 2 == 0) return false;
	else if (n < 9) return true;
	else if (n % 3 == 0) return false;
	else
	{
	    int r = sqrt(n);
		for (int i = 5; i <= r; i = i + 6)
		{
			if (n % i == 0) return false;
			if (n % (i + 2) == 0) return false;
		}
	}
	return true;
}

int main()
{
    clock_t startTime;
    startTime = clock();

    long long ans = 0;
	for (int i = 1; i <= NUM; i++)
	{
	    if (isPrime(i))
	    {
	        ans = ans + i;
	        //cout << i << " ";
	    }

	}
	cout << ans << endl;

	clock_t endTime;
    endTime = clock();
    double runTime = (endTime - startTime) / (double)CLOCKS_PER_SEC;
    cout << "Run Time:" << runTime << endl;
	return 0;
}

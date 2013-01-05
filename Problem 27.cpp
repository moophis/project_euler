/*Euler published the remarkable quadratic formula:

	n^2 + n + 41

 It turns out that the formula will produce 40 primes
 for the consecutive values n = 0 to 39. However, when
 n = 40, 40^2 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41,
 and certainly when n = 41, 41^2 + 41 + 41 is clearly
 divisible by 41.

 Using computers, the incredible formula  n^2 - 79n + 1601 was discovered,
 which produces 80 primes for the consecutive values n = 0 to 79.
 The product of the coefficients, -79 and 1601, is -126479.

 Considering quadratics of the form:

 n^2 + an + b, where |a|<1000 and |b|<1000

 where |n| is the modulus/absolute value of n
 e.g. |11| = 11 and |-4| = 4

 Find the product of the coefficients, a and b, for the
 quadratic expression that produces the maximum number of primes for
 consecutive values of n, starting with n = 0.
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>

using namespace std;

vector<int> prime_tab;

bool is_prime(int n)
{
	n = abs(n);
	if (n == 0) return false;
	if (n == 1) return false;
	else if (n < 4) return true;
	else if (n % 2 == 0) return false;
	else if (n < 9) return true;
	else if (n % 3 == 0) return false;
	else
	{
	    int r = (int) sqrt(n);
		for (int i = 5; i <= r; i = i + 6)
		{
			if (n % i == 0) return false;
			if (n % (i + 2) == 0) return false;
		}
	}
	return true;
}


void make_primetab(int range)
{
	assert(range > 0);

	for (int i = 0; i < range; i++) {
		if ( is_prime(i) )
			prime_tab.push_back(i);
	}
}

int do_coefficient_mul()
{
	int a, b, cur_a, cur_b;
	int cnt = 2;		// by default, P(0), P(1) are prime
	int maxval = 0;
	int ans;

	make_primetab(2000);
	/*
	 * Role 1: b = P(0) must be a prime number;
	 * Role 2: |1 + a + b| = |p(1)| must be a prime number.
	 */
	for (int i = 0; i < prime_tab.size(); i++) {
		if ( prime_tab[i] >= 1000 )
			break;
			
		// when b > 0, P(1) > 0
		b = prime_tab[i];
		for (int j = 0; j < prime_tab.size(); j++) {
			a = prime_tab[j] - b - 1;
			cnt = 2;
			while ( is_prime(cnt * cnt + a * cnt + b) )
				cnt++;
			if (cnt > maxval) {
				maxval = cnt;
				cur_a = a;
				cur_b = b;
				ans = a * b;
			}
		}

		// when b > 0, P(1) < 0
		for (int j = 0; j < p_num; j++) {
			a = -prime_tab[j] - b - 1;
			cnt = 2;
			if (abs(a) >= 1000)
				break;
			while ( is_prime(cnt * cnt + a * cnt + b) )
				cnt++;
			if (cnt > maxval) {
				maxval = cnt;
				cur_a = a;
				cur_b = b;
				ans = a * b;
			}
		}

		// when b < 0, P(1) > 0
		b = -prime_tab[i];
		for (int j = 0; j < p_num; j++) {
			a = prime_tab[j] - b - 1;
			cnt = 2;
			if (a >= 1000)
				break;
			while ( is_prime(cnt * cnt + a * cnt + b) )
				cnt++;
			if (cnt > maxval) {
				maxval = cnt;
				cur_a = a;
				cur_b = b;
				ans = a * b;
			}
		}

		// when b < 0, P(1) < 0
		for (int j = 0; j < p_num; j++) {
			a = -prime_tab[j] - b - 1;
			cnt = 2;
			while ( is_prime(cnt * cnt + a * cnt + b) )
				cnt++;
			if (cnt > maxval) {
				maxval = cnt;
				cur_a = a;
				cur_b = b;
				ans = a * b;
			}
		}
	}

	cout << "a = " << cur_a << " b = " << cur_b
		 << " maxval = " << maxval << endl;
	return ans;
}

int main()
{
	cout << do_coefficient_mul() << endl;
	return 0;
}

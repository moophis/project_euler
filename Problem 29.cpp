/*
 * Consider all integer combinations of a^b for 2 <= a <= 5 and 2 <= b <= 5:

	2^2=4,  2^3=8,   2^4=16,  2^5=32
	3^2=9,  3^3=27,  3^4=81,  3^5=243
	4^2=16, 4^3=64,  4^4=256, 4^5=1024
	5^2=25, 5^3=125, 5^4=625, 5^5=3125

 * If they are then placed in numerical order, with any repeats removed,
 * we get the following sequence of 15 distinct terms:

	4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125

 * How many distinct terms are in the sequence generated
 * by a^b for 2 <= a <= 100 and 2 <= b <= 100?
 */
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

struct sci_num {
	int m_base;
	int m_index;
};

bool to_scientific(int n, int *base, int *index)
{
	assert(n > 0);
	int t = 2;
	int cnt;
	int nc;

	if ( n == 1 )  return false;
	for ( ; t <= n; t++ ) {
//		cout << "t = " << t << endl;
		if ( n % t != 0 )
			continue;
//		cout << " enter!" << endl;
		cnt = 0;
		nc = n;
		while ( nc % t == 0 ) {
			cnt++;
			nc = nc / t;
			if ( nc == 1 )
				goto end;
//		cout << " --Not finished: n = " << n
//		     << " t = " << t << endl;
		}
	}

end:
	*base = t;
	*index = cnt;
	return true;
}

int find_distinct(int from, int to)
{
	assert(to >= from && from >= 2);

	int len = to - from + 1;
	int base, index;
	int dup_cnt = 0;       // # of duplicated numbers
	struct sci_num **data;

	data = new struct sci_num* [len];
	for (int i = 0; i < len; i++)
		data[i] = new struct sci_num[len];

	/**
	 * basics:
	 *  1. only numbers which base can be represented as
	 *     n*n*n*...*n (more than one time) may have chance to be identical to others.
	 *  2. numbers in lower rows and have identical pairs must
	 *     point northeastward to their counterparts.
	 *  3. the replicative element will be set to {-1, XX}.
	 */
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			to_scientific(from + i, &base, &index);
			data[i][j].m_base  = base;
			data[i][j].m_index = (from + j) * index;

			if ( j == len - 1 || i == 0 )
				continue;
			// now find duplicated elements
			for (int m = i; m >= 0; m--) {
				for (int n = j + 1; n < len; n++) {
					if ( data[m][n].m_base == -1 )
						continue;
					if ( data[i][j].m_base == data[m][n].m_base
						 && data[i][j].m_index == data[m][n].m_index ) {
						data[m][n].m_base  = -1;
						dup_cnt++;
					}
				}
			}
		}
	}

	for (int i = 0; i < len; i++)
		delete data[i];
	delete data;

	return len * len - dup_cnt;
}

int main()
{
	cout << find_distinct(2, 100) << endl;

	return 0;
}

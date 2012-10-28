/*
 * Starting in the top left corner of a 2*2 grid,
 * there are 6 routes (without backtracking) to the bottom right corner.
 * How many routes are there through a 20*20 grid?
 */
#include <iostream>

using namespace std;
int main()
{
    long long ans = 1;
	for (int i = 1; i <= 20; i++)
	{
	    ans = ans * (20 + i);
	    ans = ans / i;
	}
	cout << ans << endl;
	return 0;
}

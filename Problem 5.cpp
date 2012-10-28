/*
 * 2520 is the smallest number that can be divided by
 * each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly
 * divisible by all of the numbers from 1 to 20?
 */
#include <iostream>
#define NUM 20
#define MAX(a, b) ((a) >= (b) ? (a) : (b))
using namespace std;

int visitTab[NUM + 1];           //count the minimum required multipliers
/*
 * Hints: I firstly build an array from 1 to 20. The content of visitTab[i]
 * means the times by which to get the desired number needs being multipied by i.
 * So the point should be finding the minimum times of each multiplier i needed.
 */
int main()
{
	int ans = 1;
	for (int i = 0; i <= NUM; i++)
		visitTab[i] = 0;
	for (int i = 2; i <= NUM; i++)
	{
	    cout << "dealing with " << i << endl;
	    int current = i;
		for (int j = 2; j <= current; j++)
		{
			if (current % j) continue;
			else
			{
				int count = 0;
				do
				{
					current = current / j;
					count++;
				} while (current > 1);
				visitTab[j] = MAX(visitTab[j], count);
			}
		}
	}
	for (int i = 0; i <= NUM; i++)
	{
		for (int j = 0; j < visitTab[i]; j++)
			ans = ans * i;
	}
	cout << ans << endl;
	return 0;
}

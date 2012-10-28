/*
 * A palindromic number reads the same both ways. The largest palindrome
 * made from the product of two 2-digit numbers is 9009 = 91 * 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int multiplier1,multiplier2,maxPal = 1;
	for (int i = 100; i < 1000; i++)
		for (int j = i; j < 1000; j++)
		{
			int results = i * j,result = results;
			bool isPal = true;
			vector<int> bits;
			while (results)
			{
				bits.push_back(results % 10);
				results = results / 10;
			}
			for (int k = 0; k < bits.size() - 1 - k; k++)
				if(bits[k] != bits[bits.size() - 1 - k])
				{
					isPal = false;
					break;
				}
			if (isPal)
				if (result > maxPal)
				{
					maxPal = result;
					multiplier1 = i;
					multiplier2 = j;
				}
		}
		cout << "The largerst palindromic number is: " << maxPal
			 << " = " << multiplier1 << " * " << multiplier2 << endl;
	return 0;
}

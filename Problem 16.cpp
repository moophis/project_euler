/*
 * 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 * What is the sum of the digits of the number 2^1000?
 */
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int arr[1000];
	int ans = 0;
	int topbit = 1;
	memset(arr, 0, sizeof(arr));
	arr[0] = 1;
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < topbit; j++)
			arr[j] *= 2;
		for (int j = 0; j < topbit; j++)
		{
			arr[j + 1] += arr[j] / 10;
			arr[j] = arr[j] % 10;
			if (arr[topbit] != 0)
				topbit++;
		}
	}
	for (int i = 0; i < 1000; i++)
		ans += arr[i];
	cout << ans << endl;
	return 0;
}

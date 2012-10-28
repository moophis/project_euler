#include <iostream>
using namespace std;

int sumFactorDigit(int base)
{
	int results[200];
	int sum = 0;

	for (int i = 0; i < 200; i++)
        results[i] = 0;
	results[0] = 1;

	for (int i = 1; i <= base; i++) {
		int carry = 0;
		int tmp = 0;

		for (int j = 0; j < 200; j++) {
			tmp = results[j] * i;
			results[j] = (tmp + carry) % 10;
			carry = (tmp + carry) / 10;
		}
	}

	for (int j = 0; j < 200; j++)
		sum += results[j];

	return sum;
}
int main()
{
	cout << sumFactorDigit(100);
	return 0;
}

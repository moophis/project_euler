/*
 * Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
 * (Data is in the file "Pro13.txt")
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int i = 0;
	char c,arr[5001];
	FILE *fp = fopen("Pro13.txt", "r");
	while ((c = fgetc(fp)) != EOF)
        if (c != '\n')
            arr[i++] = c;
    arr[i] = '\0';

	int ans[60], now = 0;
	int bitpos = 49;	//initially calculate ones place
	int carry = 0;		//initially the carry is zero

	for (int i = 0; i < 60; i++)
        ans[i] = 0;
	while (bitpos >=0)
	{
		int results = 0;
		results += carry;
		for (int i = 0; i < 100; i++)
			results = results + arr[i * 50 + bitpos] - '0';
		ans[now++] = results % 10;
		carry = results / 10;
		//cout << carry;
		bitpos--;
	}
	//deal with the latest carry
	while (carry > 9)
	{
		ans[now++] = carry % 10;
		carry = carry / 10;
	}
	ans[now] = carry;       //highest place
	//display
	for (int i = 0; i < 10; i++)
		cout << ans[now--];
    cout << endl;
    for (int i = 0; i < 60; i++)
        cout << ans[i];
	return 0;
}

/*
 A unit fraction contains 1 in the numerator. The decimal representation
 of the unit fractions with denominators 2 to 10 are given:

	1/2	= 	0.5
	1/3	= 	0.(3)
	1/4	= 	0.25
	1/5	= 	0.2
	1/6	= 	0.1(6)
	1/7	= 	0.(142857)
	1/8	= 	0.125
	1/9	= 	0.(1)
	1/10	= 	0.1
 Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle.
 It can be seen that 1/7 has a 6-digit recurring cycle.

 Find the value of d < 1000 for which 1/d contains the longest recurring cycle
 in its decimal fraction part.
 */

#include <iostream>
#include <vector>

#define DEBUG 0
using namespace std;

int cycle_len(int den)
{
	int num = 1, div_now, res_now, len = 0;
	vector<int> res, div;

	for (int i = 0; ; i++) {
		if (num / den == 0)
			num = num * 10;
		if (num % den == 0)
			break;

		div_now = num / den;
		res_now = num % den;
        num     = res_now;

		if (i != 0) {
            for (int j = 0; j < div.size(); j++) {
                if (div[j] == div_now) {
                    if (res[j] == res_now) {
                    #if DEBUG
                        cout << "div_now = " << div_now << endl
                             << "res_now = " << res_now << endl;
                        cout << "div: ";
                        for (int i = 0; i < div.size(); i++) {
                            cout.width(3);
                            cout << left << div[i] << " ";
                        }
                        cout << endl;
                        cout << "res: ";
                        for (int i = 0; i < res.size(); i++) {
                            cout.width(3);
                            cout << left << res[i] << " ";
                        }
                        cout << endl;
                    #endif
                        return div.size() - j;
                    }
                }
            }
		}
		div.push_back(div_now);
        res.push_back(res_now);
	}

	return 0;
}

int main()
{
	int t, maxind = 0, maxlen = 0;

	for (int i = 2; i < 1000; i++)
        if ((t = cycle_len(i)) >= maxlen) {
            maxind = i;
            maxlen = t;
        }

	cout << maxind << endl;

	return 0;
}


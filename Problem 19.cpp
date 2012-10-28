/* How many Sundays fell on the first of the month
 * during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 * ans: 171.
 */
#include <iostream>
using namespace std;

typedef enum _Week
{
    Monday = 0,
    Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
}Week;

int monthLength[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isLeap(int year)
{
    if (year % 400 == 0) return true;
    else if (year % 100 == 0) return false;
    else if (year % 4 == 0) return true;
    else return false;
}

int main()
{
    int counter = 0;
    Week nextFirstDay = Monday;
    for (int i = 1900; i <= 2000; i++)
    {
        monthLength[1] = isLeap(i) ? 29 : 28;  // specify February length

        for (int j = 0; j < 12; j++)
        {
            if (i == 2000 && j == 11) break;
            // nextFirstDay: what weekday the first day of next month (j+1) is
            if (nextFirstDay == Sunday)
                if (i == 1900) continue;
                else counter++;
            nextFirstDay = (Week) ((nextFirstDay + monthLength[j]) % 7);
        }
    }

    cout << counter << endl;
    return 0;
}

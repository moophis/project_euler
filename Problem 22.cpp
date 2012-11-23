/*
 * Using names.txt (right click and 'Save Link/Target As...'),
   a 46K text file containing over five-thousand first names,
   begin by sorting it into alphabetical order. Then working out the alphabetical value for each name,
   multiply this value by its alphabetical position in the list to obtain a name score.

  For example, when the list is sorted into alphabetical order, COLIN,
  which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list.
  So, COLIN would obtain a score of 938 * 53 = 49714.

  What is the total of all the name scores in the file?
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> in_vec;

/* deal with the input file */
void read_input(const char *filename)
{
	char buffer[64];
	fstream input(filename, fstream::in);

	while (!input.eof()) {
		input.getline(buffer, 3, '"');

		input.getline(buffer, 32, '"');
		in_vec.push_back(buffer);
	}

	input.close();
}

/* Calculate the word value defined by this problem  */
int word_worth(string str)
{
    int counter = 0;
    string::iterator it;
    for (it = str.begin(); it < str.end(); it++)
        counter += (int) *it - 0x40;    // convert ASCII into value

    return counter;
}

/* Comparing function for sort() from C++ library */
bool str_cmp(const string &s1, const string &s2)
{
    return s1 < s2;
}

/* Calculate final score of each word */
unsigned int score(int pos)
{
    return word_worth(in_vec[pos]) * pos;
}

int main()
{
    long result = 0;
    read_input("Pro22.txt");
    sort(in_vec.begin(), in_vec.end(), str_cmp);

    for (int i = 1; i < in_vec.size(); i++) {
        result += score(i);
    }

    cout << result << endl;

	return 0;
}

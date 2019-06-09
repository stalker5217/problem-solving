#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;



int main(int argc, char** argv)
{
	//freopen("input.txt", "r", stdin);
	int test_case;
	cin >> test_case;

	for (int t = 1; t <= test_case; t++) {
		int month, day;
		cin >> month >> day;

		int m[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		int total = 0;
		for (int i = 1; i < month; i++) {
			total += m[i];
		}

		total += day;
		total += 3;
		total %= 7;

		cout << "#" << t << " " << total << "\n";
	}


	return 0;
}
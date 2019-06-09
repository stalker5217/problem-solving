#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int s_month, s_day;
		int e_month, e_day;
		int total = 0;

		cin >> s_month >> s_day >> e_month >> e_day;

		if (s_month < e_month) {
			for (int i = s_month + 1; i <= e_month - 1; i++) {
				total += month[i];
			}

			total += month[s_month] - s_day + 1;
			total += e_day;
		}

		else {
			total = e_day - s_day + 1;
		}

		cout << "#" << test_case << " " << total << endl;
	}

	return 0;
}
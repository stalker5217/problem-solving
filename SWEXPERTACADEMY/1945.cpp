#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int num;
		cin >> num;
		int _2 = 0;
		int _3 = 0;
		int _5 = 0;
		int _7 = 0;
		int _11 = 0;

		while (true) {
			if (num % 2 == 0) {
				_2++;

				if (num == 2)
					break;
				else
					num /= 2;
			}

			if (num % 3 == 0) {
				_3++;

				if (num == 3)
					break;
				else
					num /= 3;
			}

			if (num % 5 == 0) {
				_5++;

				if (num == 5)
					break;
				else
					num /= 5;
			}

			if (num % 7 == 0) {
				_7++;

				if (num == 7)
					break;
				else
					num /= 7;
			}

			if (num % 11 == 0) {
				_11++;

				if (num == 11)
					break;
				else
					num /= 11;
			}
		}


		cout << "#" << test_case << " ";
		cout << _2 << " ";
		cout << _3 << " ";
		cout << _5 << " ";
		cout << _7 << " ";
		cout << _11 << " " << endl;
	}
	return 0;
}
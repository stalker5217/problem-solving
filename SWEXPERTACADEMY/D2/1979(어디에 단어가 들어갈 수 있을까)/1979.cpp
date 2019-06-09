#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;

	//  freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int arr[15][15];
		int size;
		cin >> size;

		int text;
		cin >> text;

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				cin >> arr[i][j];

		int len = 0;
		int cnt = 0;

		for (int i = 0; i < size; i++) {
			if (text == len)
				cnt++;
			len = 0;

			for (int j = 0; j < size; j++) {
				if (arr[i][j] == 0) {
					if (text == len)
						cnt++;
					len = 0;
				}

				else
					len++;
			}
		}

		if (text == len)
			cnt++;
		len = 0;
		for (int j = 0; j < size; j++) {
			if (text == len)
				cnt++;
			len = 0;

			for (int i = 0; i < size; i++) {
				if (arr[i][j] == 0) {
					if (text == len)
						cnt++;
					len = 0;
				}

				else
					len++;
			}
		}

		if (text == len)
			cnt++;

		cout << "#" << test_case << " " << cnt << endl;
	}

	return 0;
}
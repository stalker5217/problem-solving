#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <map>

using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int arr1[20];
		int arr2[20];

		int len1, len2;
		cin >> len1 >> len2;

		for (int i = 0; i < len1; i++)
			cin >> arr1[i];

		for (int i = 0; i < len2; i++)
			cin >> arr2[i];

		int max = -5000000;
		int value;

		if (len2 > len1) {
			for (int i = 0; i <= len2 - len1; i++) {
				value = 0;
				for (int j = 0; j < len1; j++)
					value += arr1[j] * arr2[j + i];

				if (max < value)
					max = value;
			}
		}

		else {
			for (int i = 0; i <= len1 - len2; i++) {
				value = 0;
				for (int j = 0; j < len2; j++)
					value += arr2[j] * arr1[j + i];

				if (max < value)
					max = value;
			}
		}

		cout << "#" << test_case << " " << max << endl;

	}

	return 0;
}
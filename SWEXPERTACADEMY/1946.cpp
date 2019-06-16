#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <list>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;

		char *alphabet = new char[n];
		int *cnt = new int[n];

		for (int i = 0; i < n; i++) {
			cin >> alphabet[i];
			cin >> cnt[i];
		}

		cout << "#" << test_case << endl;
		int k = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < cnt[i]; j++) {
				if (k == 9) {
					cout << alphabet[i] << endl;
					k = 0;
				}
				else {
					cout << alphabet[i];
					k++;
				}
			}
		}

		cout << endl;
		delete[]alphabet;
		delete[]cnt;
	}
	return 0;
}
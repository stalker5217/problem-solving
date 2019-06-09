#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int test_case;
	cin >> test_case;

	int prime = 0;

	for (int t = 1; t <= test_case; t++) {
		int num;
		bool isPrime = true;
		cin >> num;

		if (num <= 1)
			continue;

		else {
			for (int i = 2; i <= num / 2; i++) {
				if (num % i == 0) {
					isPrime = false;
					break;
				}
			}
		}

		if (isPrime)
			prime++;

	}

	cout << prime << endl;

	return 0;
}
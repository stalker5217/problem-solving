#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);

	while (true) {
		int lower, upper;
		cin >> lower;

		if (lower == 0)
			break;

		upper = lower * 2;
		lower += 1;

		int cnt = 0;
		for (int i = upper; i >= lower; i--) {
			bool isPrime = true;
			if (i <= 1)
				continue;

			for (int j = 2; j <= sqrt(i); j++) {
				if (i % j == 0) {
					isPrime = false;
					break;
				}
			}
			if (isPrime == true) {
				cnt++;
			}
		}

		cout << cnt << endl;
	}
	return 0;
}
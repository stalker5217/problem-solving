#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);

	int lower, upper;
	cin >> lower >> upper;

	int min, sum = 0;
	for (int i = upper; i >= lower; i--) {
		bool isPrime = true;
		if (i <= 1)
			continue;
		
		for (int j = 2; j <= i / 2; j++) {
			if (i % j == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime == true) {
			sum += i;
			min = i;
		}
	}

	if (sum == 0) {
		cout << "-1" << endl;
	}
	else
		cout << sum << endl << min << endl;
	return 0;
}
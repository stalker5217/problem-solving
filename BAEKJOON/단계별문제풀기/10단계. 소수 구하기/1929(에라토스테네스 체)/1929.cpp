#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);

	int lower, upper;
	cin >> lower;
	cin >> upper;
	
	for (int i = lower; i <= upper; i++) {
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
			// endl은 존나게 무겁다
			printf("%d\n", i);
		}
	}

	return 0;
}
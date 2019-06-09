#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdint>

using namespace std;

int main() {
	int testCase;
	cin >> testCase;

	for (int t = 0; t < testCase; t++) {
		int sum = 0;
		double avg;

		for (int i = 0; i < 10; i++) {
			int temp;
			cin >> temp;

			sum += temp;
		}

		avg = (double)sum / 10;
		avg += 0.5;

		int result = (int)avg;

		printf("#%d %d\n", t + 1, result);

	}
}
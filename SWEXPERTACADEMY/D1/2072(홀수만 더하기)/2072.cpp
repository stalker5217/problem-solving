#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdint>

using namespace std;

int main() {
	int testCase;
	cin >> testCase;

	for (int t = 0; t < testCase; t++) {
		int sum = 0;

		for (int i = 0; i < 10; i++) {
			int temp;
			cin >> temp;

			if (temp % 2 == 1)
				sum += temp;
		}


		printf("#%d %d\n", t + 1, sum);

	}
}
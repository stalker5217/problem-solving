#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdint>

using namespace std;

int main() {
	int testCase;
	cin >> testCase;

	for (int t = 0; t < testCase; t++) {
		int max = INT32_MIN;
		int temp;

		for (int i = 0; i < 10; i++) {
			cin >> temp;

			if (max < temp)
				max = temp;
		}

		cout << "#" << t + 1 << " " << max << endl;
	}
}
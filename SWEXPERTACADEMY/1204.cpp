#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

using namespace std;

int main() {
	int testCase;
	cin >> testCase;

	for (int t = 0; t < testCase; t++) {
		int *arr = new int[101];

		memset(arr, 0, sizeof(int) * 101);

		int a;
		cin >> a;

		for (int i = 0; i < 1000; i++) {
			int temp;
			cin >> temp;
			arr[temp] += 1;
		}

		int maxIndex = 0;
		for (int i = 0; i <= 100; i++) {
			if (arr[maxIndex] <= arr[i])
				maxIndex = i;
		}

		cout << "#" << t + 1 << " " << maxIndex << endl;
	}
}
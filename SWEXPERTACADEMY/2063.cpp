#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int testCase;
	cin >> testCase;

	int *arr = new int[testCase];

	for (int i = 0; i < testCase; i++)
		cin >> arr[i];

	std::sort(arr, arr + testCase);

	cout << arr[testCase / 2];
}
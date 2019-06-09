#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


int main() {
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		int arr[3];
		cin >> arr[0] >> arr[1] >> arr[2];

		int result;
		if (arr[0] == arr[1]) {
			result = arr[2];
		}
		else if (arr[0] == arr[2]) {
			result = arr[1];
		}
		else if (arr[1] == arr[2]) {
			result = arr[0];
		}

		cout << "#" << test_case << " " << result << "\n";
	}

	return 0;
}
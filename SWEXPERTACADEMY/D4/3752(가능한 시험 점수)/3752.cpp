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
		int N;
		cin >> N;

		int* score = new int[N];
		int max = 0;
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			max += temp;
			score[i] = temp;
		}

		int* isValid = new int[max + 1];
		memset(isValid, 0, sizeof(int) * (max + 1));

		isValid[0] = 1;
		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = max; j >= 0; --j) {
				if (isValid[j] == 1) {
					isValid[j + score[i]] = 1;
				}
			}
		}

		for (int i = 0; i <= max; ++i) {
			if (isValid[i] > 0)
				cnt++;
		}

		delete[] score;
		delete[] isValid;

		cout << "#" << test_case << " " << cnt << "\n";
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

/*
두 정수 N, B(1 ≤ N ≤ 20, 1 ≤ B ≤ S) 주어진다.
S는 두 번째 줄에서 주어지는 점원들 키의 합이다.
*/
int N, B;

int mymin;
vector<int> height;
vector<int> choice;

void combination(int len, int offset, int c) {
	if (c == 0) {
		int sum = 0;
		for (int i = 0; i < choice.size(); ++i) {
			sum += choice[i];
		}

		int temp = sum - B;
		if (temp >= 0 && temp < mymin) {
			mymin = temp;
		}

		return;
	}

	else {
		for (int i = offset; i <= len - c; ++i) {
			choice.push_back(height[i]);
			combination(len, i + 1, c - 1);
			choice.pop_back();
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {

		cin >> N >> B;
		height.clear();
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			height.push_back(temp);
		}

		mymin = 100000000;
		choice.clear();
		for (int i = 1; i <= N; ++i) {
			combination(N, 0, i);
		}

		cout << "#" << test_case << " " << mymin << "\n";
	}

	return 0;
}
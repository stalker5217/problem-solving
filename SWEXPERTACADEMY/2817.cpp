#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int N, K;
int cnt;
vector<int> src;
vector<int> choice;

void solution(int offset, int val) {
	for (int i = offset; i < N; i++) {
		int cur = val + src[i];

		if (cur == K)
			cnt++;
		else if (cur < K) {
			solution(i + 1, cur);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> N >> K;

		src.clear();
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			src.push_back(temp);
		}

		choice.clear();
		cnt = 0;
		solution(0, 0);

		cout << "#" << test_case << " " << cnt << "\n";
	}

	return 0;
}
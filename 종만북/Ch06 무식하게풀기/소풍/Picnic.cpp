#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<pair<int, int>> fri;
vector<pair<int, int>> result;
int studentNum;
int pairNum;
int cnt;

void combination(int start, int k);

int main(){
	//freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		

		cin >> studentNum >> pairNum;

		fri.clear();
		result.clear();
		cnt = 0;

		for (int i = 0; i < pairNum; i++) {
			int a, b;
			cin >> a >> b;
			fri.push_back(make_pair(a, b));
		}

		combination(0, studentNum / 2);

		cout << cnt << "\n";
	}

	return 0;
}

void combination(int start, int k) {
	if (k == 0) {
		bool student[10] = { false };
		for (int i = 0; i < result.size(); i++) {
			student[result[i].first] = true;
			student[result[i].second] = true;
		}

		bool allMatch = true;
		for (int i = 0; i < studentNum; i++) {
			if (student[i] == false) {
				allMatch = false;
			}
		}

		if (allMatch) {
			cnt++;
		}
	}

	else {
		for (int i = start; i <= pairNum - k; i++) {
			result.push_back(fri[i]);
			combination(i + 1, k - 1);
			result.pop_back();
		}
	}
}
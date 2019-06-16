#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <memory.h>

using namespace std;

int map[100][100];
int rightMax;
int bottomMax;

void calRight();
void calBottom();

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.second < b.second) {
		return true;
	}

	else if (a.second == b.second) {
		return a.first < b.first;
	}

	else {
		return false;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	
	int R, C, K;
	cin >> R >> C >> K;

	
	for (int i = 0; i < 100; i++) {
		memset(map[i], 0, 100 * sizeof(int));
	}

	// ÃÊ±âÈ­
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}
	rightMax = 3;
	bottomMax = 3;

	int cnt = 0;
	int result;
	
	while(true) {
		if (map[R-1][C-1] == K) {
			result = cnt;
			break;
		}

		if (cnt == 100) {
			result = -1;
			break;
		}
		
		if (bottomMax < rightMax)
			calBottom();
		else
			calRight();

		cnt++;
	}

	cout << result;

	return 0;
}

void calRight() {
	int flag[101];
	int newRightMax = rightMax;
	memset(flag, 0, 101 * sizeof(int));

	for (int row = 0; row < bottomMax; row++) {
		for (int i = 0; i < rightMax; i++) {
			if (map[row][i] > 0) {
				flag[map[row][i]]++;
				map[row][i] = 0;
			}
		}

		vector<pair<int, int> > result;
		for (int i = 1; i <= 100; i++) {
			if (flag[i] > 0) {
				result.push_back(make_pair(i, flag[i]));
				flag[i] = 0;
			}
		}

		sort(result.begin(), result.end(), compare);

		for (int i = 0; i < result.size(); i++) {
			map[row][2 * i] = result[i].first;
			map[row][2 * i + 1] = result[i].second;
		}

		if (newRightMax < result.size() * 2) {
			newRightMax = result.size() * 2;
		}
	}

	rightMax = newRightMax;
}

void calBottom() {
	int flag[101];
	int newBottomMax = bottomMax;
	memset(flag, 0, 101 * sizeof(int));

	for (int col = 0; col < rightMax; col++) {
		for (int i = 0; i < bottomMax; i++) {
			if (map[i][col] > 0) {
				flag[map[i][col]]++;
				map[i][col] = 0;
			}
		}

		vector<pair<int, int> > result;
		for (int i = 1; i <= 100; i++) {
			if (flag[i] > 0) {
				result.push_back(make_pair(i, flag[i]));
				flag[i] = 0;
			}
		}

		sort(result.begin(), result.end(), compare);

		for (int i = 0; i < result.size(); i++) {
			map[2 * i][col] = result[i].first;
			map[2 * i + 1][col] = result[i].second;
		}

		if (newBottomMax < result.size() * 2) {
			newBottomMax = result.size() * 2;
		}
	}

	bottomMax = newBottomMax;
}


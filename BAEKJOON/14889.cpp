#define DEBUG 0
#define LOG(string) cout << string

#define MYMAX 1000000000

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void grouping(int, int);

int personCnt;
int mStat[21][21];
int minStat;

vector<int> mGroup;
vector<int> otherGroup;
bool onGroup[21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	// Algorithm
	cin >> personCnt;
	for (int i = 1; i <= personCnt; i++) {
		for (int j = 1; j <= personCnt; j++) {
			cin >> mStat[i][j];
		}
	}
	memset(onGroup, 0, sizeof(bool) * 21);

	minStat = MYMAX;
	// personCnt는 항상 짝수임을 보장.
	grouping(1, personCnt / 2);

	cout << minStat;

	return 0;
}

void grouping(int offset, int k) {

	if (k == 0) {
		for (int i = 1; i <= personCnt; i++) {
			if (onGroup[i] == false) {
				otherGroup.push_back(i);
			}
		}

		int firstSum = 0;
		int secondSum = 0;

		//otherGroup.size()와 동일
		for (int i = 0; i < mGroup.size(); i++) {
			for (int j = 0; j < mGroup.size(); j++) {
				firstSum += mStat[mGroup[i]][mGroup[j]];
				secondSum += mStat[otherGroup[i]][otherGroup[j]];
			}
		}

		int result = firstSum - secondSum;
		if (result < 0) {
			result = -result;
		}

		if (result < minStat) {
			minStat = result;
		}

		otherGroup.clear();
		return;
	}

	for (int i = offset; i <= personCnt - k; i++) {
		mGroup.push_back(i);
		onGroup[i] = true;
		grouping(i + 1, k - 1);
		mGroup.pop_back();
		onGroup[i] = false;
	}
}

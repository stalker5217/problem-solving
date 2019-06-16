#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int map[50][50];
int visit[50][50];
int mapSize;
int virusCnt;
int willPollutionCnt;
int curRemainCnt;
bool pollutionAll;
int minTime;
int pollutionTime;

vector<pair<int, int> > candidateLocation;
vector<pair<int, int> > curLocation;

void mCombination(int, int);
void pollution(vector<pair<int, int> >);

pair<int, int> dir[4] = {
	make_pair(0, 1),
	make_pair(0, -1),
	make_pair(1, 0),
	make_pair(-1, 0)
};

int main() {
	freopen("input.txt", "r", stdin);
	
	cin >> mapSize >> virusCnt;

	willPollutionCnt = 0;
	pollutionAll = false;
	minTime = 1000000000;
	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			visit[i][j] = 0;
			cin >> map[i][j];

			if (map[i][j] == 0) {
				willPollutionCnt++;
			}

			if (map[i][j] == 2) {
				candidateLocation.push_back(make_pair(i, j));
			}
		}
	}
	
	if (willPollutionCnt == 0) {
		cout << 0;
		return 0;
	}

	mCombination(0, virusCnt);

	if (pollutionAll == false) {
		cout << -1;
		return 0;
	}

	else {
		cout << minTime;
		return 0;
	}
}

void mCombination(int offset, int k) {
	if (k == 0) {
		pollutionTime = -1;
		curRemainCnt = willPollutionCnt;
		
		for (int i = 0; i < mapSize; i++) {
			memset(visit[i], 0, sizeof(int) * mapSize);
		}
		for (int i = 0; i < curLocation.size(); i++) {
			visit[curLocation[i].first][curLocation[i].second] = 1;
		}

		pollution(curLocation);

		if (curRemainCnt == 0) {
			pollutionAll = true;
			
			if (pollutionTime < minTime) {
				minTime = pollutionTime;
				return;
			}
		}
		
		return;
	}

	else {
		for (int i = offset; i <= candidateLocation.size() - k; i++) {
			curLocation.push_back(candidateLocation[i]);
			mCombination(i + 1, k - 1);
			curLocation.pop_back();
		}
	}
}

void pollution(vector<pair<int, int> > virusLocation) {
	if (virusLocation.size() == 0 || curRemainCnt == 0) {
		return;
	}

	else {
		pollutionTime++;
		vector<pair<int, int> > newLocation;
		for (int i = 0; i < virusLocation.size(); i++) {
			if (map[virusLocation[i].first][virusLocation[i].second] == 0) {
				curRemainCnt--;
			}
		}

		for (int i = 0; i < virusLocation.size(); i++) {
			for (int d = 0; d < 4; d++) {
				// 경계 값, 방문, 벽 검사
				if (visit[virusLocation[i].first + dir[d].first][virusLocation[i].second + dir[d].second] == 0 &&
					map[virusLocation[i].first + dir[d].first][virusLocation[i].second + dir[d].second] != 1 &&
					virusLocation[i].first + dir[d].first >= 0 &&
					virusLocation[i].first + dir[d].first < mapSize &&
					virusLocation[i].second + dir[d].second >= 0 &&
					virusLocation[i].second + dir[d].second < mapSize
					) {
					visit[virusLocation[i].first + dir[d].first][virusLocation[i].second + dir[d].second] = 1;
					newLocation.push_back(make_pair(virusLocation[i].first + dir[d].first, virusLocation[i].second + dir[d].second));
				}
			}
		}
		pollution(newLocation);
	}
}
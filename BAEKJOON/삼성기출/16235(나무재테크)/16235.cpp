#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>
#include <functional>

using namespace std;

pair<int, int> dir[8] = {
	make_pair(1, 0),
	make_pair(0, 1),
	make_pair(-1, 0),
	make_pair(0, -1),
	make_pair(1, 1),
	make_pair(1, -1),
	make_pair(-1, 1),
	make_pair(-1, -1)
};

int main() {
	freopen("input.txt", "r", stdin);

	int mapSize;
	int initTree;
	int lastYear;

	int soilPerYear[10][10];
	int soil[10][10];
	int newTree[10][10];
	deque<int> mtree[10][10];

	cin >> mapSize >> initTree >> lastYear;
	
	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			cin >> soilPerYear[i][j];
			soil[i][j] = 5;
		}
	}

	for (int i = 0; i < initTree; i++) {
		int r, c;
		int age;
		cin >> r >> c >> age;
		mtree[r-1][c-1].push_back(age);
	}

	for (int year = 0; year < lastYear; year++) {	
		// 봄, 여름
		for (int i = 0; i < mapSize; i++) {
			for (int j = 0; j < mapSize; j++) {
				newTree[i][j] = 0;
				int deathTreeIndex = -1;
				for (int k = 0; k < mtree[i][j].size(); k++) {
					if (soil[i][j] >= mtree[i][j][k]) {
						soil[i][j] -= mtree[i][j][k];
						++mtree[i][j][k];
					}
					else {
						deathTreeIndex = k;
						break;
					}
				}
				
				if (deathTreeIndex != -1) {
					for (int l = mtree[i][j].size() - 1; l >= deathTreeIndex; l--) {
						soil[i][j] += (mtree[i][j][l] / 2);
						mtree[i][j].pop_back();
					}
				}
			}
		}
		
		//가을
		for (int i = 0; i < mapSize; i++) {
			for (int j = 0; j < mapSize; j++) {
				for (int k = 0; k < mtree[i][j].size(); k++) {
					if (mtree[i][j][k] % 5 == 0) {
						for (int d = 0; d < 8; d++) {
							if (i + dir[d].first >= 0 && i + dir[d].first < mapSize &&
								j + dir[d].second >= 0 && j + dir[d].second < mapSize) {
								newTree[i + dir[d].first][j + dir[d].second]++;
							}
						}
					}
				}
			}
		}

		// 겨울
		for (int i = 0; i < mapSize; i++) {
			for (int j = 0; j < mapSize; j++) {
				for (int k = 0; k < newTree[i][j]; k++) {
					mtree[i][j].push_front(1);
				}
				soil[i][j] += soilPerYear[i][j];
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			if (mtree[i][j].size() > 0) {
				cnt += mtree[i][j].size();
			}
		}
	}

	cout << cnt;
}

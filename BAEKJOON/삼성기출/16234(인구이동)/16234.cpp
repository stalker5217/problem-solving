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

vector<pair<int, int>> * findGroup(vector<pair<int, int>>*, int, int);

int mapSize, L, R;
int map[50][50];
int visit[50][50];

pair<int, int> dir[4] = {
	make_pair(1, 0),
	make_pair(0, 1),
	make_pair(-1, 0),
	make_pair(0, -1)
};

int main() {
	freopen("input.txt", "r", stdin);

	cin >> mapSize >> L >> R;

	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			cin >> map[i][j];
		}
	}

	int cnt = 0;
	while (true) {
		vector<vector<pair<int, int>>> unionList;

		for (int i = 0; i < mapSize; i++) {
			for (int j = 0; j < mapSize; j++) {
				visit[i][j] = 0;
			}
		}

		for (int i = 0; i < mapSize; i++) {
			for (int j = 0; j < mapSize; j++) {
				if (visit[i][j] == 1)
					continue;
				else {
					vector<pair<int, int>> * group = new vector<pair<int, int>>;
					findGroup(group, i, j);

					if (group->size() > 1) {
						unionList.push_back(*group);
					}
				}
			}
		}

		if (unionList.size() == 0) {
			break;
		}

		cnt++;
		for (int i = 0; i < unionList.size(); i++) {
			int sum = 0;
			for (int a = 0; a < unionList[i].size(); a++) {
				sum += map[unionList[i][a].first][unionList[i][a].second];
			}
			int avg = sum / unionList[i].size();
			for (int a = 0; a < unionList[i].size(); a++) {
				map[unionList[i][a].first][unionList[i][a].second] = avg;
			}
		}
	}
	
	cout << cnt;
}

vector<pair<int,int>> * findGroup(vector<pair<int, int>> * group, int cur_i, int cur_j) {
	group->push_back(make_pair(cur_i, cur_j));
	visit[cur_i][cur_j] = 1;
	for (int a = 0; a < 4; a++) {
		if (cur_i + dir[a].first >= 0
			&& cur_i + dir[a].first < mapSize
			&& cur_j + dir[a].second >= 0
			&& cur_j + dir[a].second < mapSize
			&& visit[cur_i + dir[a].first][cur_j + dir[a].second] == 0
			&& abs(map[cur_i][cur_j] - map[cur_i + dir[a].first][cur_j + dir[a].second]) >= L
			&& abs(map[cur_i][cur_j] - map[cur_i + dir[a].first][cur_j + dir[a].second]) <= R
			)
		{
			findGroup(group, cur_i + dir[a].first, cur_j + dir[a].second);
		}
	}

	return group;
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

typedef struct __shark {
	int x, y;
	int size;
	int eat;
} shark;

typedef struct __locInfo {
	int distance;
	int x, y;
} locInfo;

int map[20][20];
int visit[20][20];
int mapSize;
shark babyShark;

int eatTime = 0;
queue<locInfo> searchList;

int findFeed();

bool compare(const locInfo &a, const locInfo &b) {
	if (a.x < b.x) {
		return true;
	}
	else if (a.x == b.x) {
		return a.y < b.y;
	}

	else {
		return false;
	}
}

int main() {
	freopen("input.txt", "r", stdin);

	cin >> mapSize;

	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			cin >> map[i][j];
			visit[i][j] = 0;

			if (map[i][j] == 9) {
				map[i][j] = 0;
				babyShark.x = i;
				babyShark.y = j;
				babyShark.size = 2;
				babyShark.eat = 0;
			}
		}
	}
	locInfo temp1, temp2, temp3, temp4;

	temp1.x = babyShark.x - 1;
	temp1.y = babyShark.y;
	temp1.distance = 1;

	temp2.x = babyShark.x;
	temp2.y = babyShark.y - 1;
	temp2.distance = 1;

	temp3.x = babyShark.x;
	temp3.y = babyShark.y + 1;
	temp3.distance = 1;

	temp4.x = babyShark.x + 1;
	temp4.y = babyShark.y;
	temp4.distance = 1;

	searchList.push(temp1);
	searchList.push(temp2);
	searchList.push(temp3);
	searchList.push(temp4);


	while (true) {
		if (findFeed() == 0)
			break;
		else {
			while (true) {
				if (searchList.empty()) {
					break;
				}
				else {
					searchList.pop();
				}
			}

			locInfo temp1, temp2, temp3, temp4;

			temp1.x = babyShark.x - 1;
			temp1.y = babyShark.y;
			temp1.distance = 1;

			temp2.x = babyShark.x;
			temp2.y = babyShark.y - 1;
			temp2.distance = 1;

			temp3.x = babyShark.x;
			temp3.y = babyShark.y + 1;
			temp3.distance = 1;

			temp4.x = babyShark.x + 1;
			temp4.y = babyShark.y;
			temp4.distance = 1;

			searchList.push(temp1);
			searchList.push(temp2);
			searchList.push(temp3);
			searchList.push(temp4);

			for (int i = 0; i < mapSize; i++) {
				for (int j = 0; j < mapSize; j++) {
					visit[i][j] = 0;
				}
			}
			visit[babyShark.x][babyShark.y] = 1;
		}
	}

	cout << eatTime;
}

int findFeed() {
	// 검사 대상 더 이상 존재하지 않으면 끝
	int distance = 1;

	while (true) {
		if (searchList.size() == 0) {
			return 0;
		}

		vector<locInfo> curList;
		while (true) {
			if (searchList.size() > 0 && searchList.front().distance == distance) {
				locInfo cur = searchList.front();
				curList.push_back(cur);
				searchList.pop();
			}
			else {
				break;
			}
		}

		sort(curList.begin(), curList.end(), compare);

		for (int i = 0; i < curList.size(); i++) {
			int x = curList[i].x;
			int y = curList[i].y;

			// 유효한 좌표가 아니면 끝
			if (x < 0 || x >= mapSize || y < 0 || y >= mapSize) {
				continue;
			}

			// 방문한 곳이면 끝
			if (visit[x][y] == 1) {
				continue;
			}
			visit[x][y] = 1;

			// 더 큰 물고기 있으면 못 지나감
			if (map[x][y] > babyShark.size) {
				continue;
			}

			// 탐색
			if (map[x][y] >= 1 && map[x][y] <= 6 && map[x][y] < babyShark.size) {
				map[x][y] = 0;
				babyShark.eat++;
				if (babyShark.size == babyShark.eat) {
					babyShark.size++;
					babyShark.eat = 0;
				}

				eatTime += distance;

				babyShark.x = x;
				babyShark.y = y;

				return 1;
			}

			else {
				locInfo temp1, temp2, temp3, temp4;

				temp1.x = x - 1;
				temp1.y = y;
				temp1.distance = distance + 1;

				temp2.x = x;
				temp2.y = y - 1;
				temp2.distance = distance + 1;

				temp3.x = x;
				temp3.y = y + 1;
				temp3.distance = distance + 1;

				temp4.x = x + 1;
				temp4.y = y;
				temp4.distance = distance + 1;

				searchList.push(temp1);
				searchList.push(temp2);
				searchList.push(temp3);
				searchList.push(temp4);
			}
		}
		distance++;
	}
}


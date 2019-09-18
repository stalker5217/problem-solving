#define _CRT_SECURE_NO_WARNINGS

#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef struct __Shark {
	int speed;
	int dir;
	int weight;
} Shark;

typedef enum __dir {
	TOP = 1, BOTTOM, RIGHT, LEFT
} dir;

int rowSize;
int colSize;
int sharkCnt;
Shark map[100][100];
Shark tempMap[100][100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> rowSize >> colSize >> sharkCnt;

	//초기화
	for (int i = 0; i < rowSize; i++) {
		memset(map, 0, sizeof(Shark) * colSize);
		memset(tempMap, 0, sizeof(Shark) * colSize);
	}

	for (int i = 0; i < sharkCnt; i++) {
		int row, col;
		cin >> row;
		cin >> col;

		Shark s;
		cin >> (s.speed);
		cin >> (s.dir);
		cin >> (s.weight);
		map[row - 1][col - 1] = s;
	}

	int totalWeight = 0;
	// 낚시꾼 이동
	for (int fishman = 0; fishman < colSize; ++fishman) {
		// 땅에서 가장 가까운 상어를 잡아 먹는다.
		for (int i = 0; i < rowSize; ++i) {
			if (map[i][fishman].weight > 0) {
				totalWeight += map[i][fishman].weight;
				map[i][fishman].weight = 0;
				map[i][fishman].dir = 0;
				map[i][fishman].speed = 0;
				break;
			}
		}


		// 이동
		for (int i = 0; i < rowSize; i++) {
			for (int j = 0; j < colSize; j++) {
				// 상어 존재
				if (map[i][j].weight > 0) {
					// 상어 이동
					if (map[i][j].dir == LEFT) {
						int moveDistance = map[i][j].speed % (colSize * 2 - 2);
						int tempWeight = map[i][j].weight;
						int tempSpeed = map[i][j].speed;
						int tempRow = i;
						int tempCol = j;
						int tempDir = (tempCol != 0) ? LEFT : RIGHT;

						while (true) {
							if (moveDistance == 0)
								break;

							moveDistance--;
							if (tempDir == LEFT && --tempCol == 0) {
								tempDir = RIGHT;
							}
							else if (tempDir == RIGHT && ++tempCol == (colSize - 1)) {
								tempDir = LEFT;
							}
						}

						if (tempMap[tempRow][tempCol].weight < tempWeight) {
							tempMap[tempRow][tempCol].dir = tempDir;
							tempMap[tempRow][tempCol].speed = tempSpeed;
							tempMap[tempRow][tempCol].weight = tempWeight;
						}
					}
					else if (map[i][j].dir == RIGHT) {
						int moveDistance = map[i][j].speed % (colSize * 2 - 2);
						int tempWeight = map[i][j].weight;
						int tempSpeed = map[i][j].speed;
						int tempRow = i;
						int tempCol = j;
						int tempDir = (tempCol != (colSize - 1)) ? RIGHT : LEFT;

						while (true) {
							if (moveDistance == 0)
								break;

							moveDistance--;
							if (tempDir == LEFT && --tempCol == 0) {
								tempDir = RIGHT;
							}
							else if (tempDir == RIGHT && ++tempCol == (colSize - 1)) {
								tempDir = LEFT;
							}
						}

						if (tempMap[tempRow][tempCol].weight < tempWeight) {
							tempMap[tempRow][tempCol].dir = tempDir;
							tempMap[tempRow][tempCol].speed = tempSpeed;
							tempMap[tempRow][tempCol].weight = tempWeight;
						}
					}
					else if (map[i][j].dir == TOP) {
						int moveDistance = map[i][j].speed % (rowSize * 2 - 2);
						int tempWeight = map[i][j].weight;
						int tempSpeed = map[i][j].speed;
						int tempRow = i;
						int tempCol = j;
						int tempDir = (tempRow != 0) ? TOP : BOTTOM;

						while (true) {
							if (moveDistance == 0)
								break;

							moveDistance--;
							if (tempDir == TOP && --tempRow == 0) {
								tempDir = BOTTOM;
							}
							else if (tempDir == BOTTOM && ++tempRow == (rowSize - 1)) {
								tempDir = TOP;
							}
						}

						if (tempMap[tempRow][tempCol].weight < tempWeight) {
							tempMap[tempRow][tempCol].dir = tempDir;
							tempMap[tempRow][tempCol].speed = tempSpeed;
							tempMap[tempRow][tempCol].weight = tempWeight;
						}
					}
					else if (map[i][j].dir == BOTTOM) {
						int moveDistance = map[i][j].speed % (rowSize * 2 - 2);
						int tempWeight = map[i][j].weight;
						int tempSpeed = map[i][j].speed;
						int tempRow = i;
						int tempCol = j;
						int tempDir = (tempRow != (rowSize - 1)) ? BOTTOM : TOP;

						while (true) {
							if (moveDistance == 0)
								break;

							moveDistance--;
							if (tempDir == TOP && --tempRow == 0) {
								tempDir = BOTTOM;
							}
							else if (tempDir == BOTTOM && ++tempRow == (rowSize - 1)) {
								tempDir = TOP;
							}
						}

						if (tempMap[tempRow][tempCol].weight < tempWeight) {
							tempMap[tempRow][tempCol].dir = tempDir;
							tempMap[tempRow][tempCol].speed = tempSpeed;
							tempMap[tempRow][tempCol].weight = tempWeight;
						}
					}
				}
			}
		}

		// 이동 결과 카피 및 초기화
		for (int i = 0; i < rowSize; i++) {
			memcpy(map[i], tempMap[i], sizeof(Shark) * colSize);
			memset(tempMap[i], 0, sizeof(Shark) * colSize);
		}
	}

	cout << totalWeight;

	return 0;
}

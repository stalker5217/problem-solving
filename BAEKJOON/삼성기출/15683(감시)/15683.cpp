#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int mapOrgin[8][8];
int map[8][8];
int N, M;
int blindSpot;

typedef struct __cctv{
	int row;
	int col;
	int kind;
	int direction;
} cctv;

enum {
	west = 0, east, south, north
};

void bfSearch(vector<cctv>, int);
void watch(vector<cctv>);
void watchWest(int, int);
void watchEast(int, int);
void watchNorth(int, int);
void watchSouth(int, int);

int main(){
	freopen("input.txt", "r", stdin);
	
	cin >> N >> M;
	vector<cctv> cctvArr;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;
			mapOrgin[i][j] = temp;

			if (temp >= 1 && temp <= 5) {
				cctv cur;
				cur.row = i;
				cur.col = j;
				cur.kind = temp;
				cctvArr.push_back(cur);
			}
		}
	}

	blindSpot = 64;
	bfSearch(cctvArr, 0);

	cout << blindSpot;
}
// 재귀 완전탐색 함수
void bfSearch(vector<cctv> cctvArr, int index) {
	// escape sequence
	if (index == cctvArr.size()) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				map[i][j] = mapOrgin[i][j];
			}
		}
		
		watch(cctvArr);
		int cnt = 0;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0) {
					cnt++;
				}
			}
		}

		if (cnt < blindSpot) {
			blindSpot = cnt;
		}
	}

	else {
		// 4가지 경우의 수가 있는 경우(1번, 3번, 4번 cctv)
		if (cctvArr[index].kind == 1 || cctvArr[index].kind == 3 || cctvArr[index].kind == 4) {
			for (int i = 0; i < 4; i++) {
				cctvArr[index].direction = i;
				bfSearch(cctvArr, index + 1);
			}
		}
		
		// 2가지 경우의 수가 있는 경우(2번 cctv)
		else if (cctvArr[index].kind == 2) {
			for (int i = 0; i < 3; i = i+2) {
				cctvArr[index].direction = i;
				bfSearch(cctvArr, index + 1);
			}
		}

		// 1가지 경우의 수가 있는 경우(5번 cctv)
		else {
			bfSearch(cctvArr, index + 1);
		}
	}
}

void watch(vector<cctv> cctvArr) {
	for (int i = 0 ; i < cctvArr.size() ; i++) {
		if (cctvArr[i].kind == 1) {
			if (cctvArr[i].direction == west) {
				watchWest(cctvArr[i].row, cctvArr[i].col);
			}
			else if (cctvArr[i].direction == east) {
				watchEast(cctvArr[i].row, cctvArr[i].col);
			}
			else if (cctvArr[i].direction == south) {
				watchSouth(cctvArr[i].row, cctvArr[i].col);
				
			}
			else if (cctvArr[i].direction == north) {
				watchNorth(cctvArr[i].row, cctvArr[i].col);
			}
		}

		else if (cctvArr[i].kind == 2) {
			if (cctvArr[i].direction == west) {
				watchWest(cctvArr[i].row, cctvArr[i].col);
				watchEast(cctvArr[i].row, cctvArr[i].col);
			}

			else if (cctvArr[i].direction == south) {
				watchSouth(cctvArr[i].row, cctvArr[i].col);
				watchNorth(cctvArr[i].row, cctvArr[i].col);
			}
		}

		// ㄱ자 모양. 현 위치 + 시계 반시계를 기준으로 한다.
		else if (cctvArr[i].kind == 3) {
			if (cctvArr[i].direction == west) {
				watchWest(cctvArr[i].row, cctvArr[i].col);
				watchSouth(cctvArr[i].row, cctvArr[i].col);
			}
			else if (cctvArr[i].direction == east) {
				watchEast(cctvArr[i].row, cctvArr[i].col);
				watchNorth(cctvArr[i].row, cctvArr[i].col);
			}

			else if (cctvArr[i].direction == south) {
				watchSouth(cctvArr[i].row, cctvArr[i].col);
				watchEast(cctvArr[i].row, cctvArr[i].col);
			}

			else if (cctvArr[i].direction == north) {
				watchNorth(cctvArr[i].row, cctvArr[i].col);
				watchWest(cctvArr[i].row, cctvArr[i].col);
			}
		}

		else if (cctvArr[i].kind == 4) {
			if (cctvArr[i].direction == west) {
				watchWest(cctvArr[i].row, cctvArr[i].col);
				watchSouth(cctvArr[i].row, cctvArr[i].col);
				watchNorth(cctvArr[i].row, cctvArr[i].col);
			}
			else if (cctvArr[i].direction == east) {
				watchEast(cctvArr[i].row, cctvArr[i].col);
				watchNorth(cctvArr[i].row, cctvArr[i].col);
				watchSouth(cctvArr[i].row, cctvArr[i].col);
			}

			else if (cctvArr[i].direction == south) {
				watchSouth(cctvArr[i].row, cctvArr[i].col);
				watchWest(cctvArr[i].row, cctvArr[i].col);
				watchEast(cctvArr[i].row, cctvArr[i].col);
			}

			else if (cctvArr[i].direction == north) {
				watchNorth(cctvArr[i].row, cctvArr[i].col);
				watchEast(cctvArr[i].row, cctvArr[i].col);
				watchWest(cctvArr[i].row, cctvArr[i].col);
			}
		}

		else if (cctvArr[i].kind == 5) {
			watchWest(cctvArr[i].row, cctvArr[i].col);
			watchEast(cctvArr[i].row, cctvArr[i].col);
			watchSouth(cctvArr[i].row, cctvArr[i].col);
			watchNorth(cctvArr[i].row, cctvArr[i].col);
		}
	}
}

void watchEast(int i, int j) {
	for (int a = j; a < M ; a++) {
		if (map[i][a] == 6) {
			break;
		}
		else {
			map[i][a] = -1;
		}
	}
}

void watchWest(int i, int j) {
	for (int a = j ; a >= 0 ; a--) {
		if (map[i][a] == 6) {
			break;
		}
		else {
			map[i][a] = -1;
		}
	}
}

void watchSouth(int i, int j) {
	for (int a = i; a < N; a++) {
		if (map[a][j] == 6) {
			break;
		}
		else {
			map[a][j] = -1;
		}
	}
}

void watchNorth(int i, int j) {
	for (int a = i ; a >= 0 ; a--) {
		if (map[a][j] == 6) {
			break;
		}
		else {
			map[a][j] = -1;
		}
	}
}
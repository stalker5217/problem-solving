#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <stack>

using namespace std;

int ** ice;
int ** melt;
int ** visit;

int r, c;

void travel(int x, int y) {
	visit[x][y] = 1;

	if (x - 1 >= 0 && ice[x - 1][y] > 0 && visit[x - 1][y] == 0)
		travel(x - 1, y);
	if (x + 1 < r && ice[x + 1][y] > 0 && visit[x+1][y] == 0)
		travel(x + 1, y);
	if (y - 1 >= 0 && ice[x][y - 1] > 0 && visit[x][y - 1] == 0)
		travel(x, y - 1);
	if (y + 1 < c && ice[x][y + 1] > 0 && visit[x][y + 1] == 0)
		travel(x, y + 1);
}


int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	cin >> r >> c;

	ice = new int*[r];
	melt = new int*[r];
	visit = new int*[r];

	for (int i = 0; i < r; i++) {
		ice[i] = new int[c];
		melt[i] = new int[c];
		visit[i] = new int[c];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> ice[i][j];
			melt[i][j] = 0;
			visit[i][j] = 0;
		}
	}

	int year = 0;
	while (true) {
		year++;
		// 녹을 얼음 결정.
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (ice[i][j] != 0) {
					int melCnt = 0;
					if (i - 1 >= 0 && ice[i - 1][j] == 0)
						melCnt++;
					if (i + 1 < r && ice[i + 1][j] == 0)
						melCnt++;
					if (j - 1 >= 0 && ice[i][j - 1] == 0)
						melCnt++;
					if (j + 1 < c && ice[i][j + 1] == 0)
						melCnt++;

					melt[i][j] = melCnt;
				}
			}
		}

		

		// 얼음 녹이기
		bool existIce = false;
		int x, y;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				ice[i][j] -= melt[i][j];
				if (ice[i][j] < 0)
					ice[i][j] = 0;

				if (ice[i][j] > 0) {
					existIce = true;
					x = i;
					y = j;
				}
			}
		}

		

		if (existIce == false) {
			cout << 0 << endl;
			break;
		}

		travel(x, y);


		// 하나 골라서 탐색 후 방문하지 못한 곳이 있다면 두 덩이 이상임을 의미
		bool div = false;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (ice[i][j] > 0 && visit[i][j] == 0) {
					div = true;
					break;
				}
			}
			if (div == true)
				break;
		}

		if (div) {
			cout << year << endl;
			break;
		}
			

		// 초기화
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				melt[i][j] = 0;
				visit[i][j] = 0;
			}
		}
	}

	// memory 해제
	for (int i = 0; i < r; i++) {
		delete[] ice[i];
		delete[] melt[i];
		delete[] visit[i];
	}

	delete[] ice;
	delete[] melt;
	delete[] visit;

	return 0;
}
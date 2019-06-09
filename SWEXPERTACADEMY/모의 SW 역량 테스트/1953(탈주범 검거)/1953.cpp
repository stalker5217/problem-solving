#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int N, M; // 지도의 가로, 세로
int R, C; // 현 위치 가로, 세로 좌표 값
int L; // 시간

int map[50][50];
int badGuy[50][50];
int remain_time[50][50];

enum { TOP = 0, BOTTOM, LEFT, RIGHT };

void find_location(int x, int y, int remain, int whereBy) {
	    /*
		    1 = 상, 하, 좌, 우
			    2 = 상, 하
				    3 = 좌, 우
					    4 = 상, 우
						    5 = 하, 우
							    6 = 하, 좌
								    7 = 상, 좌
									    */
										// 바운더리를 넘으면 걸러낸다.
	if (x < 0 || x >= N || y < 0 || y >= M)
		return;

	// 파이프 없으면 걸러낸다.
	if (map[x][y] == 0)
		return;

	// 방문한 지점이면 걸러낸다.
	if (badGuy[x][y] == 1 && remain_time[x][y] > remain)
		return;

	// 여기서 모양 안 맞는거 걸러내기.
	int cur = map[x][y];
	if (whereBy == TOP) {
		if (cur == 3 || cur == 5 || cur == 6)
			return;
	}
	else if (whereBy == BOTTOM) {
		if (cur == 3 || cur == 4 || cur == 7)
			return;
	}

	else if (whereBy == LEFT) {
		if (cur == 2 || cur == 4 || cur == 5)
			return;
	}

	else if (whereBy == RIGHT) {
		if (cur == 2 || cur == 6 || cur == 7)
			return;
	}



	if (remain == 1) {
		badGuy[x][y] = 1;
		remain_time[x][y] = 1;
		return;
	}

	else {
		badGuy[x][y] = 1;
		remain_time[x][y] = remain;
		if (map[x][y] == 1) {
			find_location(x - 1, y, remain - 1, BOTTOM); // 상
			find_location(x, y - 1, remain - 1, RIGHT); // 좌
			find_location(x + 1, y, remain - 1, TOP); // 하
			find_location(x, y + 1, remain - 1, LEFT); // 우
		}

		else if (map[x][y] == 2) {
			find_location(x - 1, y, remain - 1, BOTTOM); // 상
			find_location(x + 1, y, remain - 1, TOP); // 하
		}

		else if (map[x][y] == 3) {
			find_location(x, y - 1, remain - 1, RIGHT); // 좌
			find_location(x, y + 1, remain - 1, LEFT); // 우
		}

		else if (map[x][y] == 4) {
			find_location(x - 1, y, remain - 1, BOTTOM); // 상
			find_location(x, y + 1, remain - 1, LEFT); // 우
		}

		else if (map[x][y] == 5) {
			find_location(x + 1, y, remain - 1, TOP); // 하
			find_location(x, y + 1, remain - 1, LEFT); // 우
		}

		else if (map[x][y] == 6) {
			find_location(x, y - 1, remain - 1, RIGHT); // 좌
			find_location(x + 1, y, remain - 1, TOP); // 하
		}

		else if (map[x][y] == 7) {
			find_location(x - 1, y, remain - 1, BOTTOM); // 상
			find_location(x, y - 1, remain - 1, RIGHT); // 좌
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M;
		cin >> R >> C;
		cin >> L;

		for (int i = 0; i < 50; i++)
			for (int j = 0; j < 50; j++) {
				map[i][j] = 0;
				badGuy[i][j] = 0;
				remain_time[i][j] = 0;
			}



		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> map[i][j];


		find_location(R, C, L, -1);

		int cnt = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				if (badGuy[i][j] > 0)
					cnt++;
			}

		cout << "#" << test_case << " " << cnt << endl;
	}
	return 0;
}
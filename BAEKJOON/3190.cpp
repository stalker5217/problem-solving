#define _CRT_SECURE_NO_WARNINGS

#define DEBUG 0
#define LOG(string) cout << string

#define NONE 0
#define SNAKE 1
#define APPLE 2

#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3

#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>

using namespace std;

int map[100][100];
int N; // 지도 크기
int K; // 사과 개수
int L; // 방향 변환 횟수
int time;

deque<pair<int, char> > command;

struct __snake {
	int dir;
	deque<pair<int, int> > body;
} snake;

pair<int, int> direction[4] = {
	make_pair(0, 1),
	make_pair(1, 0),
	make_pair(0, -1),
	make_pair(-1, 0)
};

void game();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> N >> K;
	// 사과 위치 잡기
	for (int i = 0; i < K; i++) {
		int row, col;
		cin >> row >> col;
		row -= 1;
		col -= 1;
		map[row][col] = APPLE;
	}

	cin >> L;
	for (int i = 0; i < L; i++) {
		int second;
		char dir;

		cin >> second >> dir;
		command.push_back(make_pair(second, dir));
	}

	time = 0;
	snake.dir = EAST;
	snake.body.push_back(make_pair(0, 0));
	game();

	cout << time;

	return 0;
}

void game() {
	while (1) {
		time++;
		// 방향 검사
		int nextRow = snake.body[snake.body.size() - 1].first + direction[snake.dir].first;
		int nextCol = snake.body[snake.body.size() - 1].second + direction[snake.dir].second;

		// 벽에 닿으면 게임 종료
		if (nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= N) {
			return;
		}

		// 본인 몸통 만나면 게임 종료
		if (map[nextRow][nextCol] == SNAKE) {
			return;
		}
		// 아무 것도 없는 경우.
		else if (map[nextRow][nextCol] == NONE) {
			int tailRow = snake.body[0].first;
			int tailCol = snake.body[0].second;
			map[tailRow][tailCol] = NONE;
			snake.body.pop_front();

			map[nextRow][nextCol] = SNAKE;
			snake.body.push_back(make_pair(nextRow, nextCol));
		}
		// 사과가 있는 경우
		else if (map[nextRow][nextCol] == APPLE) {
			snake.body.push_back(make_pair(nextRow, nextCol));
		}

		// 방향 전환
		if (command[0].first == time) {
			// 왼쪽, 반시계방향
			if (command[0].second == 'L') {
				if (snake.dir > 0) {
					snake.dir -= 1;
				}
				else {
					snake.dir = 3;
				}
			}
			// 오른쪽, 시계 방향
			else if (command[0].second == 'D') {
				if (snake.dir < 3) {
					snake.dir += 1;
				}
				else {
					snake.dir = 0;
				}
			}

			command.pop_front();
		}
	}
}
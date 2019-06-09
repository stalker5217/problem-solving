#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N; // 구슬 던지는 횟수
int W; // 가로 길이
int H; // 세로 길이

int orgin_map[15][12];
int map[15][12];

vector<int> ballList;
int mymin = 10000000;

void crush(int, int);
void down_brick();

void make_list(int level) {
	// 하나의 리스트가 완성된 경우
	if (level == 0) {

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				map[i][j] = orgin_map[i][j];

		for (int i = 0; i < ballList.size(); i++) {
			int x = ballList[i];
			int y = -1;

			// 깨질 위치 찾기.
			for (int j = 0; j < H; j++) {
				if (map[j][x] > 0) {
					y = j;
					break;
				}
			}
			if (mymin > 0) {
				crush(y, x);
				down_brick();
			}

		}
		// map 뿌시기.

		int cnt = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (map[i][j] > 0)
					cnt++;
			}
		}
		if (cnt < mymin) {
			mymin = cnt;

			            /*for (int i = 0; i < H; i++) {
						                for (int j = 0; j < W; j++)
										                    cout << map[i][j] << " ";
															                cout << endl;
																			 
																			             }
																						             cout << endl;*/
		}

		return;
	}
	else {
		for (int i = 0; i < W; i++) {
			ballList.push_back(i);
			make_list(level - 1);
			ballList.pop_back();
		}
	}
}

void crush(int y, int x) {
	if (y >= H || y < 0 || x >= W || x < 0)
		return;

	if (map[y][x] == 0)
		return;

	int temp = map[y][x];
	map[y][x] = 0;

	// 연쇄 작용
	for (int k = 1; k < temp; k++) {
		crush(y + k, x);
		crush(y - k, x);
		crush(y, x + k);
		crush(y, x - k);
	}
}

void down_brick() {
	for (int j = 0; j < W; j++) {
		deque<int> temp;
		for (int i = H - 1; i >= 0; i--) {
			if (map[i][j] > 0)
				temp.push_back(map[i][j]);
			map[i][j] = 0;
		}

		int y = H - 1;
		int cur_size = temp.size();
		for (int i = 0; i < cur_size; i++) {
			map[y][j] = temp.front();
			temp.pop_front();
			y--;
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
		cin >> N >> W >> H;

		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				cin >> orgin_map[i][j];

		mymin = 100000000;
		make_list(N);

		cout << "#" << test_case << " " << mymin << endl;
	}
	return 0;
}
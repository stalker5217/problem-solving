#define DEBUG 0
#define LOG(string) cout << string
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int N, M;
int maze[100][100];
int answer;

pair<int, int> dir[4] = {
	make_pair(0, 1),
	make_pair(0, -1),
	make_pair(1, 0),
	make_pair(-1, 0)
};

void findRoute(int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			cin >> c;
			maze[i][j] = c == '1' ? 1 : 0;
		}
	}

	findRoute(0, 0);

	cout << answer;

	return 0;
}

void findRoute(int r, int c) {
	queue<pair<int, int> > cq;
	cq.push(make_pair(r, c));

	int visited[100][100];
	for (int r = 0; r < N; r++) {
		memset(visited[r], 0, sizeof(int) * M);
	}
	visited[r][c] = 1;

	int dist = 1;
	while (!cq.empty()) {
		int size = cq.size();

		for (int s = 0; s < size; s++) {
			pair<int, int> cur = cq.front();
			cq.pop();
			// cout << cur.first << " " << cur.second << endl;

			if (cur.first == N - 1 && cur.second == M - 1) {
				answer = dist;
				return;
			}

			for (int i = 0; i < 4; i++) {
				if (cur.first + dir[i].first >= 0 &&
					cur.first + dir[i].first < N &&
					cur.second + dir[i].second >= 0 &&
					cur.second + dir[i].second < M &&
					maze[cur.first + dir[i].first][cur.second + dir[i].second] == 1 &&
					visited[cur.first + dir[i].first][cur.second + dir[i].second] == 0
					)
				{
					cq.push(make_pair(cur.first + dir[i].first, cur.second + dir[i].second));
					visited[cur.first + dir[i].first][cur.second + dir[i].second] = 1;
				}
			}

		}
		dist++;
	}
}

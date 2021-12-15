#include <iostream>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<bool> > wall(n, vector<bool>(m));
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < m ; j++) {
			char tmp; cin >> tmp;
			wall[i][j] = tmp == '1';
		}
	}

	// edge case
	if(n == 1 && m == 1) {
		cout << 1;
		return 0;
	}

	// bfs
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(0, 0), k));

	vector<vector<vector<bool> > > visit(n, vector<vector<bool> >(m, vector<bool>(k, false)));
	visit[0][0][k] = true;

	pair<int, int> dir[4] = {
		{-1, 0},
		{0, -1},
		{1, 0},
		{0, 1}
	};
	
	int dist = 0;
	while(!q.empty()) {
		dist++;
		int curSize = q.size();
		for(int i = 0 ; i < curSize ; i++) {
			pair<int, int> cur = q.front().first;
			int breakCnt = q.front().second;
			q.pop();

			for(int i = 0 ; i < 4 ; i++) {
				int nextRow = cur.first + dir[i].first;
				int nextCol = cur.second + dir[i].second;

				if(nextRow == n - 1 && nextCol == m - 1) {
					cout << dist + 1;
					return 0;
				}

				if(nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m && !visit[nextRow][nextCol][breakCnt]) {
					if(!wall[nextRow][nextCol]) {
						visit[nextRow][nextCol][breakCnt] = true;
						q.push(make_pair(make_pair(nextRow, nextCol), breakCnt));
					}
					else if(wall[nextRow][nextCol] && breakCnt > 0) {
						visit[nextRow][nextCol][breakCnt] = true;
						q.push(make_pair(make_pair(nextRow, nextCol), breakCnt - 1));
					}
				}
			}
		}
	}
	
	cout << -1;
	return 0;
}
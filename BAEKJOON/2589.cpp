#include <iostream>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int w, h;
	cin >> w >> h;
	
	vector<vector<char> > tmap(w, vector<char>(h, 0));
	for(int i = 0 ; i < w ; i++) {
		for(int j = 0 ; j < h ; j++) {
			cin >> tmap[i][j];
		}
	}

	pair<int, int> dir[4] = {
		{0, 1},
		{1, 0},
		{-1, 0},
		{0, -1}
	};

	function<int (pair<int, int>)> bfs = [&](pair<int, int> start) {
		queue<pair<int, int> > q;
		q.push(start);

		vector<vector<bool> > visit(w, vector<bool>(h, false));		
		visit[start.first][start.second] = true;

		int dist = 0;

		while(!q.empty()) {
			int curSize = q.size();
			for(int t = 0 ; t < curSize ; t++) {
				auto cur = q.front();
				q.pop();
				for(int i = 0 ; i < 4 ; i++) {
					int nextRow = cur.first + dir[i].first;
					int nextCol = cur.second + dir[i].second;

					if(nextRow >= 0 &&
					   nextRow < w &&
					   nextCol >= 0 &&
					   nextCol < h &&
					   tmap[nextRow][nextCol] == 'L' &&
					   !visit[nextRow][nextCol])
					{
						visit[nextRow][nextCol] = true;
						q.push({nextRow, nextCol});
					}
				}
			}
			
			dist++;
		};

		return dist - 1;
	};

	int answer = -1;
	for(int i = 0 ; i < w ; i++) {
		for(int j = 0 ; j < h ; j++) {
			if(tmap[i][j] == 'L') {
				answer = max(answer, bfs({i, j}));
			}
		}
	}

	cout << answer;

	return 0;
}
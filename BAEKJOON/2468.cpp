#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;
	vector<vector<int> > area(n, vector<int>(n));
	int minHeight = 101;
	int maxHeight = -1;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++) {
			cin >> area[i][j];

			minHeight = min(minHeight, area[i][j]);
			maxHeight = max(maxHeight, area[i][j]);
		}
	}

	pair<int, int> dir[4] = {
		{-1, 0},
		{0, -1},
		{1, 0},
		{0, 1}
	};

	function<void (vector<vector<bool> >&, const pair<int, int>, const int)> dfs = [&](vector<vector<bool> >& visit, const pair<int, int> cur, const int baseHeight) {
		for(int i = 0 ; i < 4 ; i++) {
			int nextRow = cur.first + dir[i].first;
			int nextCol = cur.second + dir[i].second;

			if(nextRow >= 0 && nextRow < n 
			&& nextCol >= 0 && nextCol < n
			&& !visit[nextRow][nextCol]
			&& area[nextRow][nextCol] > baseHeight)
			{
				visit[nextRow][nextCol] = true;
				dfs(visit, {nextRow, nextCol}, baseHeight);
			}
		}
	};

	int maxSafeCnt = 1;
	for(int baseHeight = minHeight ; baseHeight < maxHeight ; baseHeight++) {
		vector<vector<bool> > visit(n, vector<bool>(n, false));
		int safeCnt = 0;

		for(int i = 0 ; i < area.size() ; i++) {
			for(int j = 0 ; j < area[i].size() ; j++) {
				if(!visit[i][j] && area[i][j] > baseHeight) {
					visit[i][j] = true;
					dfs(visit, {i, j}, baseHeight);
					safeCnt++;
				}
			}
		}

		maxSafeCnt = max(maxSafeCnt, safeCnt);
	}

	cout << maxSafeCnt;

	return 0;
}
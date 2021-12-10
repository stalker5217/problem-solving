#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<vector<int> > forest(n, vector<int>(n, 0));
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++) {
			cin >> forest[i][j];
		}
	}

	vector<vector<int> > dp(n, vector<int>(n, -1));
	pair<int, int> dir[4] = {
		{-1, 0},
		{0, -1},
		{1, 0},
		{0, 1}
	};

	function<int (pair<int, int>)> dfs = [&](pair<int, int> cur) {
		int& possibleCnt = dp[cur.first][cur.second];

		if(possibleCnt == -1) {
			possibleCnt = 1;
			int nextPossibleCnt = 0;
			for(int i = 0 ; i < 4 ; i++) {
				int nextRow = cur.first + dir[i].first;
				int nextCol = cur.second + dir[i].second;

				if(nextRow >= 0
				&& nextRow < n
				&& nextCol >= 0
				&& nextCol < n
				&& forest[cur.first][cur.second] < forest[nextRow][nextCol]) 
				{	
					nextPossibleCnt = max(dfs({nextRow, nextCol}), nextPossibleCnt);
				}
			}

			possibleCnt += nextPossibleCnt;
		}
		
		return possibleCnt;
	};

	int answer = -1;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++) {
			answer = max(dfs({i, j}), answer);
		}
	}

	cout << answer;

	return 0;
}
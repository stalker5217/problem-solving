#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int> > board(n, vector<int>(m));
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < m ; j++) {
			char temp; cin >> temp;
			if(temp == 'H') board[i][j] = -1;
			else board[i][j] = temp - '0';
		}
	}
	
	pair<int, int> dir[4] = {
		{-1, 0},
		{0, -1},
		{1, 0},
		{0, 1}
	};
	const int INF = 2e9;

	vector<vector<int> > dp(n, vector<int>(m, -1));
	vector<vector<bool> > visit(n, vector<bool>(m, false));

	function<int (pair<int, int>)> dfs = [&](pair<int, int> pos) {
		if(pos.first < 0 || pos.first >= n || pos.second < 0 || pos.second >= m) return 0;
		if(board[pos.first][pos.second] == -1) return 0;
		if(visit[pos.first][pos.second]) return INF;

		int& cache = dp[pos.first][pos.second];
		if(cache >= 0) return cache;
		
		visit[pos.first][pos.second] = true;
		for(int i = 0 ; i < 4 ; i++) {
			int nextRow = pos.first + dir[i].first * board[pos.first][pos.second];
			int nextCol = pos.second + dir[i].second * board[pos.first][pos.second];

			cache = max(cache, dfs({nextRow, nextCol}) + 1);
		}
		visit[pos.first][pos.second] = false;

		return cache;
	};
	
	int answer = dfs({0, 0});
	if(answer >= INF) answer = -1;
	cout << answer;

	return 0;
}
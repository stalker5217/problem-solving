#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c;
	cin >> r >> c;
	
	vector<vector<bool> > isBuilding(r, vector<bool>(c));
	for(int i = 0 ; i < r ; i++) {
		for(int j = 0 ; j < c ; j++) {
			char tmp; cin >> tmp;
			isBuilding[i][j] = tmp == 'x';
		}
	}
	
	pair<int, int> dir[3] = {
		{-1, 1},
		{0, 1},
		{1, 1}
	};

	vector<vector<bool> > visit(r, vector<bool>(c, false));
	function<bool (pair<int, int>)> dfs = [&](pair<int, int> cur) {
		visit[cur.first][cur.second] = true;
		if(cur.second == c - 1) return true;

		for(int i = 0 ; i < 3 ; i++) {
			int nextRow = cur.first + dir[i].first;
			int nextCol = cur.second + dir[i].second;

			if(nextRow >= 0 && nextRow < r && nextCol >= 0 && nextCol < c 
			   && !visit[nextRow][nextCol]
			   && !isBuilding[nextRow][nextCol]) 
			{
				if(dfs({nextRow, nextCol})) return true;
			}
		}

		return false;
	};

	int answer = 0;
	for(int i = 0 ; i < r ; i++) {
		if(dfs({i, 0})) answer++;
	}

	cout << answer;

	return 0;
}
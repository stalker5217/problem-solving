#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n, k;
	cin >> m >> n >> k;

	vector<vector<bool> > area(m, vector<bool>(n, true));
	
	// 제외 영역 설정
	for(int i = 0 ; i < k ; i++) {
		pair<int, int> start, end;
		cin >> start.first >> start.second;
		cin >> end.first >> end.second;

		for(int a = start.first ; a < end.first ; a++) {
			for(int b = start.second ; b < end.second ; b++) {
				area[b][a] = false;
			}
		}
	}

	// 영역 체크
	pair<int, int> dir[4] = {
		{-1, 0},
		{1, 0},
		{0, -1},
		{0, 1}
	};
	function<void (pair<int, int>, int &)> dfs = [&](pair<int, int> pos, int & curSize) {
		curSize++;
		for(int i = 0 ; i < 4 ; i++) {
			int nextRow = pos.first + dir[i].first;	
			int nextCol = pos.second + dir[i].second;

			if(nextRow >= 0 && nextRow < m && nextCol >= 0 && nextCol < n && area[nextRow][nextCol]) {
				area[nextRow][nextCol] = false;
				dfs({nextRow, nextCol}, curSize);
			}
		}
	};

	int curSize = 0;
	vector<int> areaSize;
	for(int i = 0 ; i < m ; i++) {
		for(int j = 0 ; j < n ; j++) {
			if(area[i][j]) {
				area[i][j] = false;

				curSize = 0;
				dfs({i, j}, curSize);
				areaSize.push_back(curSize);
			}
		}
	}
	sort(areaSize.begin(), areaSize.end());

	cout << areaSize.size() << "\n";
	for(int size : areaSize) cout << size << " ";

	return 0;
}
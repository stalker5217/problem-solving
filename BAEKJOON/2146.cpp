#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<vector<int> >  arr(n, vector<int>(n));
	for(int i = 0 ; i < n ; i ++) {
		for(int j = 0 ; j < n ; j++) {
			cin >> arr[i][j];
		}
	}

	pair<int, int> dir[4] = {
		{-1, 0},
		{0, -1},
		{1, 0},
		{0, 1}
	};

	// 대륙을 넘버링
	function<void (pair<int, int>, const int)> landLabeling = [&](pair<int, int> start, const int label) {
		queue<pair<int, int> > q;
		q.push(start);
		arr[start.first][start.second] = label;
		while(!q.empty()) {
			auto cur = q.front();
			q.pop();
			for(int i = 0 ; i < 4 ; i++) {
				int nextRow = cur.first + dir[i].first;
				int nextCol = cur.second + dir[i].second;
			
				if(nextRow >= 0
					&& nextRow < n
					&& nextCol >= 0
					&& nextCol < n
					&& arr[nextRow][nextCol] == 1)
				{
					q.push({nextRow, nextCol});
					arr[nextRow][nextCol] = label;
				}
			}
		}
	};
	
	int curLabel = 2;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++) {
			if(arr[i][j] == 1) landLabeling({i, j}, curLabel++);
		}
	}

	function<pair<bool, int> (pair<int, int>)> getMinDist = [&](pair<int, int> start) {
		int distance = 0;
		int label = arr[start.first][start.second];
		vector<vector<bool> > visit(n, vector<bool>(n, false));
		queue<pair<int, int> > q;
		q.push(start);
		
		while(!q.empty()) {
			int curSize = q.size();
			for(int i = 0 ; i < curSize ; i++) {
				auto cur = q.front();
				q.pop();

				for(int i = 0 ; i < 4 ; i++) {
					int nextRow = cur.first + dir[i].first;
					int nextCol = cur.second + dir[i].second;

					if(nextRow >= 0
					   && nextRow < n
					   && nextCol >= 0
					   && nextCol < n)
					{
						if(arr[nextRow][nextCol] == 0 && !visit[nextRow][nextCol]) {
							visit[nextRow][nextCol] = true;
							q.push({nextRow, nextCol});
						}
						else if(arr[nextRow][nextCol] > 0 && arr[nextRow][nextCol] != label) return make_pair(true, distance);
					}
				}
			}

			distance++;
		}

		return make_pair(false, 0);
	};

	int minDist = 1000;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++) {
			if(arr[i][j]) {
				auto result = getMinDist({i, j});
				if(result.first) minDist = min(minDist, result.second);
			}
		}
	}

	cout << minDist;

	return 0;
}
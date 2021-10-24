#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int testCase; cin >> testCase;
	while(testCase--) {
		int l; cin >> l;
		pair<int, int> start;
		pair<int, int> target;

		cin >> start.first >> start.second;
		cin >> target.first >> target.second;

		pair<int, int> dirs[8] = {
			{2, 1},
			{2, -1},
			{-2, 1},
			{-2, -1},
			{1, 2},
			{1, -2},
			{-1, 2},
			{-1, -2}
		};

		vector<vector<bool> > visit(l, vector<bool>(l, false));
		
		int answer = [&](pair<int, int> start) {
			int cnt = 0;
			queue<pair<int, int> > q;
			q.push(start);
			visit[start.first][start.second] = true;
			
			while(!q.empty()) {
				int qSize = q.size();

				for(int i = 0 ; i < qSize ; i++) {
					pair<int, int> cur = q.front();
					q.pop();

					if(cur.first == target.first && cur.second == target.second) return cnt;
						
					for(pair<int, int> dir : dirs) {
						int nextX = cur.first + dir.first;
						int nextY = cur.second + dir.second;

						if(nextX >= 0 && nextX < l && nextY >= 0 && nextY < l && !visit[nextX][nextY]) {
							visit[nextX][nextY] = true;
							q.push({nextX, nextY});
						} 
					}
				}

				cnt++;
			}

			return -1;
		}(start);

		cout << answer << "\n";
	}
	
    return 0;
}
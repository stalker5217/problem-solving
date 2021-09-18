#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int testCase;
	cin >> testCase;
	while(testCase--) {
		// 작년 순위
		int n;
		cin >> n;
		vector<int> lastYearRank;
		for(int i = 0 ; i < n ; i++) {
			int temp;
			cin >> temp;
			lastYearRank.push_back(temp);
		}

		// 그래프 연결 정보 생성
		vector<vector<bool> > isConnected(n+1, vector<bool>(n+1, false));
		for(int i = 0 ; i < n ; i++) {
			for(int j = i + 1 ; j < n ; j++) {
				isConnected[lastYearRank[i]][lastYearRank[j]] = true;
			}
		}

		// 올해 바뀐 순위 정보 수정
		int m;
		cin >> m;
		for(int i = 0 ; i < m ; i++) {
			int a, b;
			cin >> a >> b;
			if(isConnected[a][b]) {
				isConnected[a][b] = false;
				isConnected[b][a] = true;
			}
			else if(isConnected[b][a]){
				isConnected[b][a] = false;
				isConnected[a][b] = true;
			}
		}

		// indegree 측정
		vector<int> indegree(n+1, 0);
		for(int i = 1 ; i <= n ; i++) {
			for(int j = 1 ; j <= n ; j++) {
				if(isConnected[i][j]) ++indegree[j];
			}
		}

		// Topological Sort
		queue<int> q;
		for(int i = 1 ; i <= n ; i++) if(indegree[i] == 0) q.push(i);

		vector<int> answer;
		while(!q.empty()) {
			int currentTeam = q.front();
			q.pop();

			answer.push_back(currentTeam);

			for(int i = 1 ; i <= n ; i++) {
				if(isConnected[currentTeam][i]) {
					if(--indegree[i] == 0) q.push(i);
				}
			}
		}

		if(answer.size() == n) {
			for(int currentTeam : answer) {
				cout << currentTeam << " ";
			}
			cout << "\n";
		}
		else {
			cout << "IMPOSSIBLE\n";
		}
	}

    return 0;
}
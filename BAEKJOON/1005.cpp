#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;
	cin >> test_case;
	while(test_case--){
		int buildingCnt, ruleCnt;
		cin >> buildingCnt >> ruleCnt;

		vector<int> buildTime(buildingCnt + 1, 0);
		for(int i = 1 ; i <= buildingCnt ; i++){
			cin >> buildTime[i];
		}

		vector<vector<int> > adj(buildingCnt + 1, vector<int>(0));
		vector<int> indegreeCnt(buildingCnt + 1, 0);
		for(int i = 0 ; i < ruleCnt ; i++){
			int start, end;
			cin >> start >> end;
			adj[start].push_back(end);
			indegreeCnt[end]++;
		}
		
		int targetBuilding;
		cin >> targetBuilding;

		queue<int> q;
		for(int i = 1 ; i <= buildingCnt ; i++){
			if(indegreeCnt[i] == 0) q.push(i);
		}

		vector<int> time(buildingCnt + 1, 0);
		while(indegreeCnt[targetBuilding] > 0){
			int cur = q.front();
			q.pop();

			for(int next : adj[cur]){
				time[next] = max(time[next], time[cur] + buildTime[cur]);
				if(--indegreeCnt[next] == 0) q.push(next);
			}
		}

		cout << time[targetBuilding] + buildTime[targetBuilding] << "\n";
	}
    
    return 0;
}
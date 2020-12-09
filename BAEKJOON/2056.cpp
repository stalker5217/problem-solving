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

	int n;
	cin >> n;
	vector<int> cost(n+1, 0);
	vector<vector<int> > adj(n+1);
	vector<int> indegree(n+1, 0);
	queue<int> q;
	for(int i = 1 ; i <= n ; i++){
		cin >> cost[i];
		cin >> indegree[i];

		for(int cnt = 0 ; cnt < indegree[i] ; cnt++){
			int preceding;
			cin >> preceding;
			adj[preceding].push_back(i);
		}
	}

	
	for(int i = 1 ; i <= n ; i++){
		if(indegree[i] == 0) q.push(i);
	}

	vector<int> time(n+1, 0);
	copy(cost.begin(), cost.end(), time.begin());
	while(!q.empty()){
		int cur = q.front();
		q.pop();

		for(int next : adj[cur]){
			time[next] = max(time[next], time[cur] + cost[next]);
			
			if(--indegree[next] == 0) q.push(next);
		}
	}
	
	int answer = -1;
	for(int i = 1 ; i <= n ; i++){
		answer = max(answer, time[i]);
	}

	cout << answer;

    return 0;
}
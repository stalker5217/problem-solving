#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n;
	cin >> n;

	vector<int> time(n + 1 , 0);
	vector<int> indegree(n + 1, 0);
	vector<vector<int> > adj(n + 1);
	for(int i = 1 ; i <= n; i++){
		cin >> time[i];

		while(true){
			int pre;
			cin >> pre;

			if(pre == -1) break;

			indegree[i]++;
			adj[pre].push_back(i);
		}
	}

	queue<int> q;

	for(int i = 1 ; i <= n ; i++){
		if(indegree[i] == 0) q.push(i);
	}

	vector<int> preCondition(n+1, 0);
	while(!q.empty()){
		int curNode = q.front();
		q.pop();

		for(int i = 0 ; i < adj[curNode].size() ; i++){
			int nextNode = adj[curNode][i];

			preCondition[nextNode] = max(preCondition[nextNode], preCondition[curNode] + time[curNode]);
			
			if(--indegree[nextNode] == 0) q.push(nextNode);
		}
	}

	for(int i = 1 ; i <= n ; i++){
		cout << preCondition[i] + time[i] << "\n";
	}

    return 0;
}
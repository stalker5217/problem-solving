#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int> > adj(n+1, vector<int>(0));
	vector<int> indegreeCnt(n+1, 0);

	for(int i = 0 ; i < m ; i++){
		int start, end;
		cin >> start >> end;

		adj[start].push_back(end);
		indegreeCnt[end]++;
	}

	queue<int> q;
	for(int i = 1 ; i <= n ; i++){
		if(indegreeCnt[i] == 0) q.push(i);
	}

	while(!q.empty()){
		int curNode = q.front();
		q.pop();

		cout << curNode << " ";

		for(int i = 0 ; i < adj[curNode].size() ; i++){
			int next = adj[curNode][i];
			if(--indegreeCnt[next] == 0) q.push(next);
		}
	}

	return 0;
}
#define R 0
#define G 1
#define B 2
#define MAX 1000 * 1000 + 1

#include <iostream>
#include <queue>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int problemCnt, informationCnt;
	cin >> problemCnt >> informationCnt;

	vector<vector<int> > adj(problemCnt + 1, vector<int>(0));
	vector<int> indegree(problemCnt + 1, 0);

	for(int i = 0 ; i < informationCnt ; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b); 
		indegree[b]++;
	}

	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i = 1 ; i <= problemCnt ; i++){
		if(indegree[i] == 0) pq.push(i);
	}

	while(!pq.empty()){
		int curProblem = pq.top();
		pq.pop();

		cout << curProblem << " ";

		for(int i = 0 ; i < adj[curProblem].size() ; i++){
			int next = adj[curProblem][i];
			if(--indegree[next] == 0) pq.push(next);
		}
	}

	return 0;
}
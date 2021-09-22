#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

int v, e;
vector<vector<int> > adj;
vector<int> discovered;
vector<int> sccId;
stack<int> st;

int sccCounter = 0;
int vertexCounter = 0;

int scc(int here);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int testCase;
	cin >> testCase;
	while(testCase--) {
		adj.clear();
		discovered.clear();
		sccId.clear();
		while(!st.empty()) st.pop();

		sccCounter = 0;
		vertexCounter = 0;

		cin >> v >> e;
		adj.assign(v+1, vector<int>(0));
		for(int i = 0 ; i < e ; i++){
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
		}

		// tarjan SCC
		discovered.assign(v+1, -1);
		sccId.assign(v+1, -1);
		for(int i = 1 ; i <= v ; i++){
			if(discovered[i] == -1) scc(i);
		}

		vector<int> indegree(sccCounter, 0);
		for(int i = 1 ; i <= v ; i++) {
			for(int to : adj[i]) {
				if(sccId[i] != sccId[to]) {
					++indegree[sccId[to]];
				}
			}
		}

		int answer = 0;
		for(int i = 0 ; i < indegree.size() ; i++) {
			if(indegree[i] == 0) ++answer;
		}

		cout << answer << "\n";
	}

    return 0;
}

int scc(int here){
	int ret = discovered[here] = vertexCounter++;

	st.push(here);
	for(int next : adj[here]){
		if(discovered[next] == -1) ret = min(ret, scc(next));
		else if(sccId[next] == -1) ret = min(ret, discovered[next]);
	}

	if(ret == discovered[here]){
		while(true){
			int t = st.top();
			st.pop();

			sccId[t] = sccCounter;
			if(t == here) break;
		}
		++sccCounter;
	}

	return ret;
}
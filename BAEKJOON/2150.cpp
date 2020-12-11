#define DEBUG 0
#define LOG(string) cout << string

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

	map<int, int> idMap;
	int answerId = 0;
	int maxId = *max_element(sccId.begin(), sccId.end());
	vector<vector<int> > answer(maxId + 1, vector<int>(0));
	for(int i = 1 ; i <= v ; i++){
		if(idMap.find(sccId[i]) == idMap.end()){
			idMap[sccId[i]] = answerId++;
		}
		
		answer[idMap[sccId[i]]].push_back(i);
	}

	cout << answer.size() << "\n";
	for(int i = 0 ; i < answer.size() ; i++){
		for(int j : answer[i]){
			cout << j << " ";
		}
		cout << -1 << "\n";
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
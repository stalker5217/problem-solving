#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<int> > adj;
vector<int> discovered;
vector<int> sccId;
stack<int> st;

int n, m;
int sccCounter = 0;
int vertexCounter = 0;

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

// Tarjan SCC
void tarjanScc() {
	sccCounter = 0;
	vertexCounter = 0;

	discovered.clear();
	sccId.clear();

	discovered.assign(2 * n, -1);
	sccId.assign(2 * n, -1);

	for(int i = 0 ; i < 2 * n ; i++){
		if(discovered[i] == -1) scc(i);
	}
}

bool solve2SAT() {
	tarjanScc();

	// 해가 없는 경우
	for(int i = 0 ; i < 2 * n ; i += 2) {
		if(sccId[i] == sccId[i+1]) return false;
	}

	return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	while(cin >> n >> m) {
		// Implication Graph(함의 그래프) 생성
		adj.clear();
		adj.resize(n * 2);

		for(int i = 0 ; i < m ; i++) {
			int a, b;
			cin >> a >> b;

			a = (a > 0) ? (a - 1) * 2 : (-a - 1) * 2 + 1;
			b = (b > 0) ? (b - 1) * 2 : (-b - 1) * 2 + 1;

			int not_a = (a % 2) ? a - 1 : a + 1;
			int not_b = (b % 2) ? b - 1 : b + 1;

			adj[not_a].push_back(b); // ~a => b
			adj[not_b].push_back(a); // ~b => a
		}

		if(solve2SAT()) cout << "1\n";
		else cout << "0\n";
	}
	
    return 0;
}
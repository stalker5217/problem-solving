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
	discovered.assign(2 * n, -1);
	sccId.assign(2 * n, -1);
	for(int i = 0 ; i < 2 * n ; i++){
		if(discovered[i] == -1) scc(i);
	}
}

vector<int> solve2SAT() {
	tarjanScc();

	// 해가 없는 경우
	for(int i = 0 ; i < 2 * n ; i += 2) {
		if(sccId[i] == sccId[i+1]) return vector<int>();
	}

	// Tarjan 알고리즘에서 SCC 번호는 위상 정렬의 역순으로 배정
	// SCC 번호의 역순으로 각 정점을 정렬하면 위상 정렬 순서가 됨
	vector<pair<int, int> > order;
	for(int i = 0 ; i < 2 * n ; i++) order.push_back({-sccId[i], i});
	sort(order.begin(), order.end());

	vector<int> ret(n, -1);
	for(int i = 0 ; i < 2 * n ; i++) {
		int vertex = order[i].second;
		int variable = vertex / 2;
		int isTrue = vertex % 2 == 0;

		if(ret[variable] != -1) continue;

		ret[variable] = !isTrue;
	}

	return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n >> m;

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

	vector<int> answer = solve2SAT();

	if(answer.size() == 0) cout << "0";
	else {
		cout << "1\n";
		for(int val : answer) cout << val << " ";
	}

    return 0;
}
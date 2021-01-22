#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > adj;
vector<int> depth;
vector<int> parent;

void dfs(int, int);
int lca(int, int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
	cin >> n;

	adj.resize(n+1);
	depth.resize(n+1);
	parent.resize(n+1);

	for(int i = 0 ; i < n - 1 ; i++){
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// Depth, Parent 구하기
	dfs(1, 1);
	
	int m;
	cin >> m;
	for(int i = 0 ; i < m ; i++){
		int a, b;
		cin >> a >> b;

		cout << lca(a, b) << "\n";
	}

    return 0;
}

void dfs(int node, int curDepth){
	depth[node] = curDepth;

	for(int child : adj[node]){
		if(depth[child] == 0){
			dfs(child, curDepth + 1);
			parent[child] = node;
		}
	}
}

int lca(int a, int b){
	// a : small depth
	// b : big depth 
	if(depth[a] > depth[b]) swap(a, b);
	
	// depth 조절
	while(depth[a] < depth[b]){
		b = parent[b];
	}

	while(a != b){
		a = parent[a];
		b = parent[b];
	}

	return a;
}
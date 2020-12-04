#define DEBUG 0
#define LOG(string) cout << string
#define MAX_K 18

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int> > adj;
vector<int> depth;
vector<vector<int> > parent;

void dfs(int, int);
int lca(int, int);
void calAncestor();

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n;

	adj.resize(n+1);
	depth.resize(n+1);
	parent.assign(n+1, vector<int>(MAX_K));

	for(int i = 0 ; i < n - 1 ; i++){
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	// Depth, Parent 구하기
	dfs(1, 1);
	calAncestor();
	
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
			parent[child][0] = node;
		}
	}
}

void calAncestor(){
	for(int k = 0 ; k < MAX_K - 1 ; k++){
		for(int node = 1 ; node <= n ; node++){
			parent[node][k+1] = parent[parent[node][k]][k];
		}
	}
}

int lca(int a, int b){
	// a : small depth
	// b : big depth 
	if(depth[a] > depth[b]) swap(a, b);
	
	// depth 조절
	for(int k = MAX_K - 1 ; k >= 0 ; k--){
		if((1 << k) <= depth[b] - depth[a]){
			b = parent[b][k];
		}
	}

	if(a == b) return a;

	for(int k = MAX_K - 1 ; k >= 0 ; k--){
		if(parent[a][k] != parent[b][k]){
			a = parent[a][k];
			b = parent[b][k];
		}
	}

	return parent[a][0];
}
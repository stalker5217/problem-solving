#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct DisjointSet{
  vector<int> parent;
  vector<int> rank;

  DisjointSet(int n)
  : parent(n), rank(n, 1)
  {
    for(int i = 0 ; i < n ; i++){
      parent[i] = i;
    }
  }

  // 경로 압축 최적화
  int find(int u) {
    if(u == parent[u]) return u;
    else return parent[u] = find(parent[u]);
  }

  // u, v가 속해 있는 각각의 트리를 합친다
  void merge(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return;
    if(rank[u] > rank[v]) swap(u, v);
    parent[u] = v;
    if(rank[u] == rank[v]) ++rank[v];
  }
};

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	DisjointSet disjointSet(n);

	int answer = 0;
	for(int i = 1 ; i <= m ; i++) {
		int u, v;
		cin >> u >> v;

		if(disjointSet.find(u) == disjointSet.find(v)) {
			answer = i;
			break;
		}

		disjointSet.merge(u, v);
	}

	cout << answer;
}
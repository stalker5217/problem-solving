#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<pair<int, pair<int, int> > > edges;
	for(int i = 0 ; i < m ; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		edges.push_back({cost, {u, v}});
	}
	sort(edges.begin(), edges.end());

	class DisjointSet {
	private:
		vector<int> parent;

	public:
		DisjointSet(int n) : parent(n + 1) {
			for(int i = 1 ; i <= n ; i++) parent[i] = i;
		}

		int find(int u) {
			if(u == parent[u]) return u;
			else return parent[u] = find(parent[u]);
		}

		void merge(int u, int v) {
			u = find(u);
			v = find(v);

			if(u == v) return;

			parent[v] = u;
		}
	};

	int answer = 0;
	DisjointSet disjointSet(n);
	for(auto cur : edges) {
		int cost = cur.first;
		int u = cur.second.first;
		int v = cur.second.second;

		if(disjointSet.find(u) == disjointSet.find(v)) continue;

		disjointSet.merge(u, v);
		answer += cost;
	}

	cout << answer;

	return 0;
}
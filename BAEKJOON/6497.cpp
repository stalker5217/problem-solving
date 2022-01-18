#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet {
private:
	vector<int> parent;

public:
	DisjointSet(int n)
	: parent(n)
	{
		for(int i = 0 ; i < n ; i++) parent[i] = i;
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

int main() {
	while(true) {
		int m, n;
		cin >> m >> n;

		if(m == 0 && n == 0) break;
		
		int totalCost = 0;
		vector<pair<int, pair<int, int> > > edges;
		for(int i = 0 ; i < n ; i++) {
			int u, v, distance;
			cin >> u >> v >> distance;

			totalCost += distance;
			edges.push_back({distance, {u, v}});
		}
		sort(edges.begin(), edges.end());

		int minCost = 0;
		DisjointSet disjointSet(m);
		for(auto cur : edges) {
			int distance = cur.first;
			int u = cur.second.first;
			int v = cur.second.second;

			if(disjointSet.find(u) == disjointSet.find(v)) continue;

			disjointSet.merge(u, v);
			minCost += distance;
		}

		cout << totalCost - minCost << "\n";
	}
	
	return 0;
}
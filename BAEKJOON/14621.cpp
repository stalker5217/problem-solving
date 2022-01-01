#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<char> universityTypes(n);
	for(int i = 0 ; i < n ; i++) cin >> universityTypes[i];
	
	vector<pair<int, pair<int, int> > > edges;
	for(int i = 0 ; i < m ; i++) {
		int u, v, dist;
		cin >> u >> v >> dist;
		u--, v--;
		
		if(universityTypes[u] == universityTypes[v]) continue;
		edges.push_back({dist, {u, v}});
		edges.push_back({dist, {v, u}});
	}
	sort(edges.begin(), edges.end());

	int ret = 0;
	vector<pair<int, int> > selected;

	class DisjointSet {
	private:
		vector<int> parent;
	public:
		DisjointSet(int n) : parent(n) {
			for(int i = 0 ; i < n ; i++) {
				parent[i] = i;
			}
		}

		int find(int u) {
			if(parent[u] == u) return u;
			else return parent[u] = find(parent[u]);
		}

		void merge(int u, int v) {
			u = find(u);
			v = find(v);

			if(u == v) return;
			parent[u] = v;
		}
	};

	DisjointSet sets(n);

	for(int i = 0 ; i < edges.size() ; i++) {
		int cost = edges[i].first;
		int u = edges[i].second.first;
		int v = edges[i].second.second;

		if(sets.find(u) == sets.find(v)) continue;

		sets.merge(u, v);
		selected.push_back({u, v});
		ret += cost;
	}

	if(selected.size() == n - 1) cout << ret;
	else cout << -1;

	return 0;
}
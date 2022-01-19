#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<pair<int, pair<int, int> > > edges;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < n ; j++) {
			int cost; cin >> cost;
			if(i < j) edges.push_back({cost, {i, j}});
		}
	}
	sort(edges.begin(), edges.end());

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

	long long answer = 0;
	DisjointSet dSet(n);
	for(auto edge : edges) {
		int cost = edge.first;
		int u = edge.second.first;
		int v = edge.second.second;

		if(dSet.find(u) == dSet.find(v)) continue;

		dSet.merge(u, v);
		answer += cost;
	}

	cout << answer;

	return 0;
}
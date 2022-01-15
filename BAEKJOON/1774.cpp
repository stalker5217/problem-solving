#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>

using namespace std;

class DisjointSet {
private:
	vector<int> parent;

public:
	DisjointSet(int n) : parent(n + 1) {
		for(int i = 1 ; i <= n ; i++) {
			parent[i] = i;
		}
	}

	int find(int u) {
		if (u == parent[u]) return u;
		else return parent[u] = find(parent[u]);
	}

	void merge(int u, int v) {
		u = find(u);
		v = find(v);

		if(u == v) return;
		parent[u] = v;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	vector<pair<int, int> > positions(n + 1);
	for(int i = 1 ; i <= n ; i++) {
		cin >> positions[i].first >> positions[i].second;
	}

	vector<pair<double, pair<int, int> > > edges;
	for(int i = 1 ; i<= n ; i++) {
		for(int j = i + 1 ; j <= n ; j++) {
			double dist = sqrt(
				pow(positions[i].first - positions[j].first, 2)
				+
				pow(positions[i].second - positions[j].second, 2)
			);

			edges.push_back({dist, {i, j}});
		}
	}
	sort(edges.begin(), edges.end());

	DisjointSet disjointSet(n);
	for(int i = 0 ; i < m ; i++) {
		int u, v;
		cin >> u >> v;
		disjointSet.merge(u, v);
	}

	double answer = 0;
	for(auto cur : edges) {
		double dist = cur.first;
		int u = cur.second.first;
		int v = cur.second.second;

		if(disjointSet.find(u) == disjointSet.find(v)) continue;

		disjointSet.merge(u, v);
		answer += dist;
	}

	cout.precision(2);
	cout << fixed << answer;

	return 0;
}
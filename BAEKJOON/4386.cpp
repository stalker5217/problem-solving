#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<pair<double, double> > stars(n);
	for(int i = 0 ; i < n ; i++) {
		cin >> stars[i].first >> stars[i].second;
	}

	vector<pair<double, pair<int, int> > > edges;
	for(int i = 0 ; i < n ; i++) {
		for(int j = i + 1 ; j < n ; j++) {
			double distance = sqrt(
				pow(stars[i].first - stars[j].first, 2)
				+
				pow(stars[i].second - stars[j].second, 2)
			);

			edges.push_back({distance, {i, j}});
		}
	}
	sort(edges.begin(), edges.end());

	class DisjointSet {
	private:
		vector<int> parent;
	public:
		DisjointSet(int n) : parent(n) {
			for(int i = 0 ; i < n ; i++) 
				parent[i] = i;
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

	double answer = 0;
	DisjointSet disjointSet(n);
	for(auto cur : edges) {
		double cost = cur.first;
		int u = cur.second.first;
		int v = cur.second.second;

		if(disjointSet.find(u) == disjointSet.find(v)) continue;

		disjointSet.merge(u, v);
		answer += cost;
	}

	cout.precision(2);
	cout << fixed << answer;
}

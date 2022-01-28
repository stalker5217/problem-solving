#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<pair<int, int> > xBase, yBase, zBase;
	for(int i = 0 ; i < n ; i++) {
		int x, y, z;
		cin >> x >> y >> z;

		xBase.push_back({x, i});
		yBase.push_back({y, i});
		zBase.push_back({z, i});
	}

	sort(xBase.begin(), xBase.end());
	sort(yBase.begin(), yBase.end());
	sort(zBase.begin(), zBase.end());

	// distance, from, to
	vector<tuple<int, int, int> > edges;
	for(int i = 0 ; i < n - 1 ; i++) {
		edges.push_back({xBase[i + 1].first - xBase[i].first, xBase[i].second, xBase[i+1].second});
		edges.push_back({yBase[i + 1].first - yBase[i].first, yBase[i].second, yBase[i+1].second});
		edges.push_back({zBase[i + 1].first - zBase[i].first, zBase[i].second, zBase[i+1].second});
	}

	sort(edges.begin(), edges.end());

	class DisjointSet {
	private:
		vector<int> parent;
		vector<int> rank;

	public:
		DisjointSet(int n)
		: parent(n), rank(n, 1)
		{
			for(int i = 0 ; i < n ; i++) {
				parent[i] = i;
			}
		}

		int find(int u) {
			if(u == parent[u]) return u;
			else return parent[u] = find(parent[u]);
		}

		void merge(int u, int v) {
			u = find(u);
			v = find(v);

			if(u == v) return;
			if(rank[u] > rank[v]) swap(u, v);
			parent[u] = v;
			if(rank[u] == rank[v]) ++rank[v];
		}
	};
	DisjointSet s(n);
	
	int answer = 0;
	for(auto edge : edges) {
		int distance = get<0>(edge);
		int from = get<1>(edge);
		int to = get<2>(edge);

		if(s.find(from) != s.find(to)) {
			s.merge(from, to);
			answer += distance;
		}
	}

	cout << answer;

	return 0;
}
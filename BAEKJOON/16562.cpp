#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	
	vector<int> parent(n + 1);
	vector<int> fee(n + 1);
	for(int i = 1 ; i <= n ; i++) {
		parent[i] = i;
		cin >> fee[i];
	}

	function<int (int)> find = [&](int u) {
		if(u == parent[u]) return u;
		else return parent[u] = find(parent[u]);
	};

	auto merge = [&](int u, int v) {
		u = find(u);
		v = find(v);

		if(u == v) return;
		if(fee[u] < fee[v]) swap(u, v);
		parent[u] = v;
	};

	for(int i = 0 ; i < m ; i++) {
		int u, v;
		cin >> u >> v;
		merge(u, v);
	}

	int sum = 0;
	for(int i = 1 ; i <= n ; i++) {
		if(parent[i] == i) {
			sum += fee[i];
		}
	}
	if(sum <= k) cout << sum;
	else cout << "Oh no";

	return 0;
}
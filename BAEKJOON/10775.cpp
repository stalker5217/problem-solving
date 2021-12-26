#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int g, p;
	cin >> g >> p;
	
	vector<int> parent(g + 1);
	for(int i = 0 ; i < parent.size() ; i++) parent[i] = i;

	function<int (int)> find = [&](int n) {
		if(parent[n] == n) return n;
		else return parent[n] = find(parent[n]);
	};

	auto merge = [&](int u, int v) {
		u = find(u);
		v = find(v);

		parent[v] = u;
	};

	int answer = 0;
	while(answer < p) {
		int cur; cin >> cur;
		int target = find(cur);
		if(target == 0) break;

		merge(target - 1, target);
		answer++;
	}

	cout << answer;

	return 0;
}
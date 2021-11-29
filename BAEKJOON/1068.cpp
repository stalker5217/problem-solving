#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> parent(n, 0);
	vector<vector<int> > tree(n, vector<int>());
	int root;
	for(int i = 0 ; i < n ; i++) {
		cin >> parent[i];
		if(parent[i] == -1) root = i;
		else tree[parent[i]].push_back(i);
	}

	function<int (const vector<vector<int> >, const int)> getLeafCnt = [&](const vector<vector<int> > tree, const int num) {
		if(tree[num].size() == 0) {
			return 1;
		}

		int leafCnt = 0;
		for(int child : tree[num]) {
			leafCnt += getLeafCnt(tree, child);
		}

		return leafCnt;
	};

	int deleteTarget; cin >> deleteTarget;
	int answer = getLeafCnt(tree, root) - getLeafCnt(tree, deleteTarget);;
	if(tree[parent[deleteTarget]].size() == 1) answer++;
	cout << answer;

	return 0;
}
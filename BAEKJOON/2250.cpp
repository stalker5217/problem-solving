#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int nodeCnt; cin >> nodeCnt;
	vector<pair<int, int> > child(nodeCnt + 1);
	vector<int> parent(nodeCnt + 1, -1);
	for(int i = 0 ; i < nodeCnt ; i++) {
		int num, left, right;
		cin >> num >> left >> right;

		if(left > 0) parent[left] = num;
		if(right > 0) parent[right]= num;

		child[num].first = left;
		child[num].second = right;
	}

	vector<vector<int> > indexs;
	indexs.push_back(vector<int>()); // dummy
	function <int (int, int, int)> dfs = [&](int num, int level, int padding) {
		if(indexs.size() == level) indexs.push_back(vector<int>());

		int leftWidth = 0;
		if(child[num].first != -1) leftWidth = dfs(child[num].first, level + 1, padding);
		
		indexs[level].push_back(padding + leftWidth + 1);

		int rightWidth = 0;
		if(child[num].second != -1) rightWidth = dfs(child[num].second, level + 1, padding + leftWidth + 1);

		return 1 + leftWidth + rightWidth;
	};

	int root = find(parent.begin() + 1, parent.end(), -1) - parent.begin();
	dfs(root, 1, 0);

	int maxWidth = -1;
	int maxWidthLevel;
	for(int i = 1 ; i < indexs.size() ; i++) {
		int width;
		if(indexs[i].size() == 1) width = 1;
		else width = indexs[i][indexs[i].size() - 1] - indexs[i][0] + 1;

		if(width > maxWidth) {
			maxWidth = width;
			maxWidthLevel = i;
		}
	}

	cout << maxWidthLevel << " " << maxWidth;

	return 0;
}
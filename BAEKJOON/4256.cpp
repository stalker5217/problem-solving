#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testCase; cin >> testCase;
	while(testCase--) {
		int n; cin >> n;

		vector<int> preorder(n);
		vector<int> inorder(n);
		unordered_map<int, int> inorderIndexMap;
		for(int i = 0 ; i < n ; i++) cin >> preorder[i];
		for(int i = 0 ; i < n ; i++) cin >> inorder[i];

		vector<int> postorder;
		function<void (int, int, int, int)> getPostorder = [&](int preStart, int preEnd, int inStart, int inEnd) {
			if(preStart > preEnd || inStart > inEnd) return;

			int rootValue = preorder[preStart];
			int rootIndexOnInorder = find(inorder.begin() + inStart, inorder.begin() + inEnd, rootValue) - inorder.begin();

			getPostorder(preStart + 1, preStart + rootIndexOnInorder - inStart, inStart, rootIndexOnInorder - 1);
			getPostorder(preStart + rootIndexOnInorder - inStart + 1, preEnd, rootIndexOnInorder + 1, inEnd);
			postorder.push_back(rootValue);
		};

		getPostorder(0, n - 1, 0, n - 1);
		for(auto cur : postorder) cout << cur << " ";
		cout << "\n";
	}

	return 0;
}
#include <iostream>
#include <functional>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s; cin >> n >> s;
	vector<int> arr(n);
	for(int i = 0 ; i < n ; i++) cin >> arr[i];
	vector<int> picked;

	int answer = 0;
	function<void(int, int)> combination = [&](int k, int curPos) {
		if(k == 0) {
			int sum = 0;
			for(int cur : picked) sum += cur;
			if(sum == s) ++answer;

			return;
		}

		for(int i = curPos ; i <= arr.size() - k ; i++) {
			picked.push_back(arr[i]);
			combination(k-1, i+1);
			picked.pop_back();
		}
	};

	for(int i = 1 ; i <= arr.size() ; i++) {
		picked.clear();
		combination(i, 0);
	}
	
	cout << answer;
}
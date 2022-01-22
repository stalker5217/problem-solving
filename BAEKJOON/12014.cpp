#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testCase; cin >> testCase;

	for(int t = 1 ; t <= testCase ; t++) {
		int n, k;
		cin >> n >> k;

		vector<int> stocks(n);
		for(int i = 0 ; i < n ; i++) cin >> stocks[i];

		vector<int> lis;
		lis.push_back(0);
		for(int stock : stocks) {
			if(lis.back() < stock) lis.push_back(stock);
			else {
				int replaceIdx = lower_bound(lis.begin(), lis.end(), stock) - lis.begin();
				lis[replaceIdx] = stock;
			}
		}

		int answer = k < lis.size() ? 1 : 0;
		cout << "Case #" << t << "\n";
		cout << answer << "\n";
	}

	return 0;
}
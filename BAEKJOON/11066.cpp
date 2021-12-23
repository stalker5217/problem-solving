#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testCase; cin >> testCase;
	while(testCase--) {
		int n; cin >> n;
		vector<int> arr(n + 1);
		vector<int> partialSum(n + 1, 0);
		for(int i = 1 ; i <= n ; i++) {
			cin >> arr[i];
			partialSum[i] = partialSum[i-1] + arr[i];
		}

		// dp[i][j] = [i, j]까지의 최소 비용
		vector<vector<int> > dp(n + 1, vector<int>(n + 1, -1));
		function<int (int, int)> getMinCost = [&](int start, int end) {
			if(start > end)
				return 0;
			
			int& cache = dp[start][end];
			if(start == end) 
				return cache = 0;
			
			if(cache >= 0) 
				return cache;

			cache = 2e9;
			for(int i = start ; i <= end ; i++) {
				cache = min(
					cache, 
					getMinCost(start, i) + getMinCost(i + 1, end)
				);
			}
			
			return cache += partialSum[end] - partialSum[start - 1];
		};

		cout << getMinCost(1, n) << "\n";
	}

	return 0;
}
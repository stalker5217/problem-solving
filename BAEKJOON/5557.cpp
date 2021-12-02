#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> arr(n, 0);
	for(int i = 0 ; i < n ; i++) cin >> arr[i];

	vector<vector<long long> > dp(n, vector<long long>(21, 0));
	dp[0][arr[0]] = 1;
	for(int i = 1 ; i < n - 1 ; i++) {
		for(int j = 0 ; j <= 20 ; j++) {
			if(j + arr[i] >= 0 && j + arr[i] <= 20 && dp[i-1][j] > 0) {
				dp[i][arr[i] + j] += dp[i-1][j];
			}
			if(j - arr[i] >= 0 && j - arr[i] <= 20 && dp[i-1][j] > 0) {
				dp[i][j - arr[i]] += dp[i-1][j];
			}
		}
	}

	cout << dp[n-2][arr[n-1]];

	return 0;
}
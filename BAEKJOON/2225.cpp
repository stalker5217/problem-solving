#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	// dp[n][k] : k개의 수를 사용하여 합이 n을 만든 개수
	vector<vector<int> > dp(n + 1, vector<int>(k + 1, 0));
	for(int i = 0 ; i <= n ; i++) dp[i][1] = 1;
	
	for(int _k = 2 ; _k <= k ; _k++) {
		for(int _n = 0 ; _n <= n ; _n++) {
			for(int p = 0 ; p <= _n ; p++) {
				dp[_n][_k] += dp[p][_k-1];
				dp[_n][_k] %= 1000000000;
			}
		}
	}

	cout << dp[n][k];

	return 0;
}
#include <iostream>	
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<long long> > dp(1000001, vector<long long>(4, 0));
	dp[1][1] = 1LL; dp[1][2] = 0LL; dp[1][3] = 0LL;
	dp[2][1] = 0LL; dp[2][2] = 1LL; dp[2][3] = 0LL;
	dp[3][1] = 1LL; dp[3][2] = 1LL; dp[3][3] = 1LL;
	for(int i = 4 ; i <= 1000000 ; i++) {
		dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % 1000000009LL;
		dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % 1000000009LL;
		dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % 1000000009LL;
	}
	
	int testCase; cin >> testCase;
	while(testCase--) {
		int n; cin >> n;
		long long answer = (dp[n][1] + dp[n][2] + dp[n][3]) % 1000000009LL;
		cout << answer << "\n";
	}

	return 0;
}
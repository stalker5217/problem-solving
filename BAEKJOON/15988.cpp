#include <iostream>	
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<long long> dp(1000001, 0);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i = 4 ; i <= 1000000 ; i++) {
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
		dp[i] %= 1000000009L;
	}
	
	int testCase; cin >> testCase;
	while(testCase--) {
		int n; cin >> n;
		cout << dp[n] << "\n";
	}

	return 0;
}
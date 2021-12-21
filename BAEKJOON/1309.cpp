#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> dp(n + 1);
	dp[0] = 1; dp[1] = 3;
	for(int i = 2 ; i <= n ; i++) dp[i] = (dp[i - 2] + dp[i - 1] * 2) % 9901;

	cout << dp[n];

	return 0;
}
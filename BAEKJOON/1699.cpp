#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;
	vector<int> dp(n + 1, 100000);
	dp[0] = 0;
	for(int i = 1 ; i <= n ; i++) 
		for(int j = 1 ; i - (j * j) >= 0 ; j++) 
			dp[i] = min(dp[i], dp[i - (j * j)] + 1);
	
	cout << dp[n];

	return 0;
}
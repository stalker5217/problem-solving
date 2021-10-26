#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin >> n;
	vector<int> cost(n + 1);
	for(int i = 1 ; i <= n ; i++) cin >> cost[i];
	
	vector<int> dp(n + 1);
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= i ; j++) {
			dp[i] = max(dp[i], dp[i - j] + cost[j]);
		}
	}

	cout << dp[n];
	
	return 0;
}
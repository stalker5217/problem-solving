#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<int> coin(n, 0);
	for(int i = 0 ; i < n ; i++) cin >> coin[i];
	
	vector<int> dp(k + 1, 10005);
	dp[0] = 0;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 1 ; j <= k ; j++) {
			if(j - coin[i] >= 0) dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	int answer = dp[k] == 10005 ? -1 : dp[k];
	cout << answer; 

	return 0;
}
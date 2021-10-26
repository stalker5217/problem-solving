#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	
	vector<int> coin(n);
	for(int i = 0 ; i < n ; i++) cin >> coin[i];

	vector<int> dp(k + 1);
	dp[0] = 1;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 1 ; j <= k ; j++) {
			if(j - coin[i] >= 0) dp[j] += dp[j - coin[i]];
		}
	}

	cout << dp[k];
}
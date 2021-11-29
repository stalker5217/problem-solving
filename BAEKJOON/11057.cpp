#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<vector<int> > dp(n + 1, vector<int>(10, 0));
	
	// 첫 번째 케이스 초기화
	for(int i = 0 ; i < 10 ; i++) dp[1][i] = 1;

	for(int i = 2 ; i <= n ; i++) {
		for(int j = 0 ; j < 10 ; j++) {
			for(int k = 0 ; k <= j ; k++) {
				dp[i][j] += dp[i-1][k];
				dp[i][j] %= 10007;
			}
		}
	}

	int sum = 0;
	for(int i = 0 ; i < 10 ; i++) sum += dp[n][i];
	
	cout << sum % 10007;
}
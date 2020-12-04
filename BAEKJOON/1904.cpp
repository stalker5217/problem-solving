#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

long dp[1000001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;
	
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2 ; i <= n ; i++){
		dp[i] = (dp[i-1] + dp[i-2]) % 15746;
	}

	cout << dp[n];
	
    return 0;
}
#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

    long long dp[101][10];
	for(int i = 1 ; i <= 9 ; i++) dp[1][i] = 1;

	for(int i = 2 ; i <= n ; i++){
		for(int j = 0 ; j <= 9 ; j++){
			if(j == 0) dp[i][0] = dp[i-1][1];
			else if(j == 9) dp[i][9] = dp[i-1][8];
			else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000L;
		}
	}

    long long sum = 0;
	for(int i = 0 ; i <= 9 ; i++) sum = (sum + dp[n][i]) % 1000000000L;

	cout << sum;

    return 0;
}
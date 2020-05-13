#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long dp[101];
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	for(int i = 4 ; i <= 100 ; i++){
		dp[i] = dp[i-2] + dp[i-3];
	}

	int t;
	cin >> t;
	for(int test_case = 1 ; test_case <= t ; test_case++){
		int q;
		cin >> q;
		cout << dp[q] << "\n";
	}
    
    return 0;
}

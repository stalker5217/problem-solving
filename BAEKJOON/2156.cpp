#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMax(int a, int b, int c){
	return max(max(a, b), c);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
	cin >> n;
	vector<int> wine(n+1, 0);
	for(int i = 1 ; i <= n ; i++){
		cin >> wine[i];
	}

	vector<int> dp(n+1, 0);
	dp[0] = 0;
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];
	for(int i = 3 ; i <= n ; i++){
		dp[i] = getMax( dp[i-1],
						dp[i-2] + wine[i],
						dp[i-3] + wine[i] + wine[i-1]);
	}

	cout << dp[n];
    
    return 0;
}
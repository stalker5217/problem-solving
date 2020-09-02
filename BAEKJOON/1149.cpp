#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>

using namespace std;

int min(const int & a, const int & b);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int> > cost(n+1, vector<int>(3));
	for(int i = 1 ; i <= n ; i++) cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

	vector<vector<int> > dp(n+1, vector<int>(3));
	dp[1][0] = cost[1][0];
	dp[1][1] = cost[1][1];
	dp[1][2] = cost[1][2];
	for(int i = 1 ; i <= n ; i++){
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
	}

	int answer = dp[n][0];
	answer = (answer < dp[n][1]) ? answer : dp[n][1];
	answer = (answer < dp[n][2]) ? answer : dp[n][2];

	cout << answer;

    return 0;
}

int min(const int & a, const int & b){
	return (a < b) ? a : b;
}
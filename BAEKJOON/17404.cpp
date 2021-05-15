#define R 0
#define G 1
#define B 2
#define MAX 1000 * 1000 + 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int> > cost(n + 1, vector<int>(3));
	for(int i = 1 ; i <= n ; i++){
		cin >> cost[i][R];
		cin >> cost[i][G];
		cin >> cost[i][B];
	}

	vector<vector<int> > dp(n + 1, vector<int>(3));
	dp[1][R] = cost[1][R];
	dp[1][G] = cost[1][G];
	dp[1][B] = cost[1][B];

	int answer = MAX;
	for(int c = 0 ; c < 3 ; c++){
		for(int i = 0 ; i < 3 ; i++) dp[1][i] = (i == c) ? cost[1][i] : MAX;
	
		for(int i = 2 ; i <= n ; i++){
			dp[i][R] = min(dp[i-1][G], dp[i-1][B]) + cost[i][R];
			dp[i][G] = min(dp[i-1][R], dp[i-1][B]) + cost[i][G];
			dp[i][B] = min(dp[i-1][R], dp[i-1][G]) + cost[i][B];
		}

		for(int i = 0 ; i < 3 ; i++) if(i != c) answer = min(answer, dp[n][i]);
	}

	cout << answer;

	return 0;
}
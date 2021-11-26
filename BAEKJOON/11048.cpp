#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	vector<vector<int> > maze(n + 1, vector<int>(m + 1, 0));
	vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= m ; j++) {
			cin >> maze[i][j];
			dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + maze[i][j];
		}
	}

	cout << dp[n][m];

	return 0;
}
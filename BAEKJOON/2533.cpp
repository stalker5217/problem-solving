#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin >> n;
	vector<vector<int> > adj(n + 1, vector<int>(0));
	for(int i = 0 ; i < n ; i++) {
		int a, b; cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<bool> visit(n+1, false);
	vector<vector<int> > dp(n+1, vector<int>(2, 0));

	function<void (int)> dfs = [&](int node) {
		visit[node] = true;
		dp[node][0] = 0; dp[node][1] = 1;

		for(int next : adj[node]) {
			if(visit[next]) continue;

			dfs(next);

			dp[node][0] += dp[next][1];
			dp[node][1] += min(dp[next][0], dp[next][1]);
		}
	};

	dfs(1);
	cout << min(dp[1][0], dp[1][1]);

    return 0;
}
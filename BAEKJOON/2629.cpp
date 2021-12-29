#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> weights(n);
	int sum = 0;
	for(int i = 0 ; i < n ; i++) {
		cin >> weights[i];
		sum += weights[i];
	}

	vector<vector<bool> > dp(n + 1, vector<bool>(sum + 1, false));
	function<void (int, int)> calIsPossible = [&](int index, int sum) {
		if(index > n || dp[index][sum]) return;
		
		dp[index][sum] = true;
		calIsPossible(index + 1, sum + weights[index]);
		calIsPossible(index + 1, sum);
		calIsPossible(index + 1, abs(sum - weights[index]));
	};

	calIsPossible(0, 0);

	int m; cin >> m;
	for(int i = 0 ; i < m ; i++) {
		int measurement; cin >> measurement;
		char result;
		if(measurement > sum) result = 'N';
		else result = dp[n][measurement] ? 'Y' : 'N';
		
		cout << result << " ";
	}

	return 0;
}
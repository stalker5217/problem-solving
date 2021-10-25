#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> arr(n);
	for(int i = 0 ; i < n ; i++) cin >> arr[i];

	vector<int> dp(n);
	for(int i = 0 ; i < n ; i++) {
		dp[i] = arr[i];
		for(int j = 0 ; j < i ; j++) {
			if(arr[j] < arr[i] && dp[j] + arr[i] >= dp[i]) dp[i] = dp[j] + arr[i];
		}
	}

	int answer = *max_element(dp.begin(), dp.end());
	cout << answer;
	
	return 0;
}
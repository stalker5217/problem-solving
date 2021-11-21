#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> weights(n + 1, 0);
	for(int i = 1 ; i <= n ; i++) cin >> weights[i];
	sort(weights.begin(), weights.end());

	int sum = 0;
	for(int i = 1 ; i <= n ; i++) {
		if(sum + 1 < weights[i]) break;
		else sum += weights[i];
	}

	cout << sum + 1;

	return 0;
}
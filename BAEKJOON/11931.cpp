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

	sort(arr.begin(), arr.end(), [](auto a, auto b) {
		return a > b;
	});

	for(auto cur : arr) cout << cur << "\n";

	return 0;
}
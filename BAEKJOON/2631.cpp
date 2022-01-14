#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> lis;
	lis.push_back(0);

	for(int i = 0 ; i < n ; i++) {
		int cur; cin >> cur;

		if(cur > lis.back()) lis.push_back(cur);
		else {
			int idx = lower_bound(lis.begin(), lis.end(), cur) - lis.begin();
			lis[idx] = cur;
		}
	}

	cout << n + 1 - lis.size();

	return 0;
}
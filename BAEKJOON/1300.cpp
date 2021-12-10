#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	int k; cin >> k;

	int start = 1, end = k;
	int answer = -1;
	while(start <= end) {
		int mid = (start + end) / 2;
		
		int cnt = 0;
		for(int i = 1 ; i <= n ; i++) cnt += min(mid / i, n);
		
		if(cnt < k) start = mid + 1;
		else {
			answer = mid;
			end = mid - 1;
		}
	}

	cout << answer;

	return 0;
}
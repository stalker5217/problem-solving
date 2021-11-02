#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<long long> arr(n);
	for(int i = 0 ; i < n ; i++) cin >> arr[i];

	sort(arr.begin(), arr.end());

	int maxCnt = -1;
	long long maxCntValue = -1;
	
	long long pre = arr[0];
	int cnt = 1;
	for(int i = 1 ; i < arr.size() ; i++) {
		if(arr[i] == pre) cnt++;
		else {
			if(maxCnt < cnt) {
				maxCnt = cnt;
				maxCntValue = pre;
			}
			cnt = 1;
			pre = arr[i];
		}
	}

	if(maxCnt < cnt) {
		maxCnt = cnt;
		maxCntValue = pre;
	}

	cout << maxCntValue;

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> arr(n);
	for(int i = 0 ; i < n ; i++) cin >> arr[i];

	function<bool (vector<int> & arr)> next = [&](vector<int> & arr) {
		// arr[x] < arr[x+1]를 만족하는 가장 큰 x 값을 구하며, 존재하지 않으면 순열의 마지막임
		int i = arr.size() - 2;
		while(i >= 0 && arr[i] >= arr[i + 1]) i--;
		if(i == -1) return false;

		// arr[x] < arr[y]를 만족하는 가장 큰 y 값을 구함
		int j = arr.size() - 1;
		while(j > 0 && arr[i] >= arr[j]) j--;
		
		// arr[x], arr[y]를 교환
		swap(arr[i], arr[j]);

		// [x+1, n] 구간을 reverse
		reverse(arr.begin() + i + 1, arr.end());

		return true;
	};

	if(next(arr)) {
		for(auto cur : arr) cout << cur << " ";
	}
	else cout << -1;
	
	return 0;
}
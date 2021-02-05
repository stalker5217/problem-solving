#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l;
	cin >> n >> l;

	vector<int> arr(n, 0);
	for(int i = 0 ; i < n ; i++) cin >> arr[i];

	// value, index
	deque<pair<int, int> > d;
	for(int i = 0 ; i < n ; i++){
		// 덱에는 최대 L개의 수를 포함한다.
		if(!d.empty() && d.front().second <= i - l) d.pop_front();
		// 현재 값 보다 큰 값들은 뒤에서 모두 제거한다.
		while(!d.empty() && d.back().first > arr[i]) d.pop_back();

		d.push_back({arr[i], i});
		cout << d.front().first << " ";
	}

	return 0;
}
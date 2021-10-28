#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> arr(n);
	for(int i = 0 ; i < n ; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());

	int answer = -1;
	do {
		int sum = 0;
		for(int i = 0 ; i < arr.size() - 1 ; i++) sum += abs(arr[i] - arr[i + 1]);
		
		answer = max(answer, sum);
	} while(next_permutation(arr.begin(), arr.end()));

	cout << answer;

	return 0;
}
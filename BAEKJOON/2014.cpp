#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int k, n;
	cin >> k >> n;

	vector<int> arr(k);
	priority_queue<long long, vector<long long>, greater<long long> > pq;
	for(int i = 0 ; i < k ; i++) {
		cin >> arr[i];
		pq.push(arr[i]);
	}

	long long answer;
	while(n--) {
		answer = pq.top();
		pq.pop();

		for (int num : arr) {
			pq.push(answer * num);
			if (answer % num == 0) break;
		}
	}

	cout << answer;

	return 0;
}
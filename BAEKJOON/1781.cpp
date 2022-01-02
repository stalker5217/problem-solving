#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<pair<int, int> > assignments(n);
	for(int i = 0 ; i < n ; i++) {
		cin >> assignments[i].first;  // 데드라인 
		cin >> assignments[i].second; // 컵라면 수
	}
	sort(assignments.begin(), assignments.end());

	priority_queue<int, vector<int>, greater<int> > pq;
	int i = 0;
	int day = 1;
	while(i < n) {
		while(i < n && day == assignments[i].first) {
			if(pq.size() < day) pq.push(assignments[i].second);
			else if(pq.top() < assignments[i].second) {
				pq.pop();
				pq.push(assignments[i].second);
			}

			i++;
		}
		day++;
	}

	int noodleCnt = 0;
	while(!pq.empty()) {
		noodleCnt += pq.top();
		pq.pop();
	}

	cout << noodleCnt;

	return 0;
}
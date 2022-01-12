#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<pair<int, int> > lectures(n);
	for(int i = 0 ; i < n ; i++) {
		cin >> lectures[i].second >> lectures[i].first;
	}
	sort(lectures.begin(), lectures.end());

	priority_queue<int, vector<int>, greater<> > pq;
	int day = 1;
	int i = 0;
	while(i < lectures.size()) {
		while(day == lectures[i].first) {
			if(pq.size() < day) pq.push(lectures[i].second);
			else if(pq.top() < lectures[i].second) {
				pq.pop();
				pq.push(lectures[i].second);
			}
			
			i++;
		}

		day++;
	}

	int earn = 0;
	while(!pq.empty()) {
		earn += pq.top();
		pq.pop();
	}

	cout << earn;

	return 0;
}
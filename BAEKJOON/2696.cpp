#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testCase; cin >> testCase;
	while(testCase--) {
		priority_queue<int> lower;
		lower.push(INT_MIN); // dummy

		priority_queue<int, vector<int>, greater<int> > higher;
		higher.push(INT_MAX); // dummy
		
		int n; cin >> n;
		vector<int> answer;
		int mid; cin >> mid;
		answer.push_back(mid);
		for(int i = 1 ; i < n ; i++) {
			int temp; cin >> temp;
			
			if(temp < mid) lower.push(temp);
			else higher.push(temp);

			if(i % 2 == 0) {
				if(lower.size() > higher.size()) {
					higher.push(mid);

					mid = lower.top();
					lower.pop();
				}
				else if(lower.size() < higher.size()) {
					lower.push(mid);

					mid = higher.top();
					higher.pop();
				}

				answer.push_back(mid);
			}
		}

		cout << answer.size() << "\n";
		for(int i = 1 ; i <= answer.size() ; i++) {
			cout << answer[i - 1];
			if(i % 10 == 0) cout << "\n";
			else cout << " ";
		}
		cout << "\n";
	}

	return 0;
}
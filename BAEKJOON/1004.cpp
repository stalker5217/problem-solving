#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testCase; cin >> testCase;
	while(testCase--) {
		pair<int, int> start, end;
		cin >> start.first >> start.second;
		cin >> end.first >> end.second;

		int n; cin >> n;
		int cnt = 0;
		for(int i = 0 ; i < n ; i++) {
			pair<int, int> center;
			int r;
			cin >> center.first >> center.second >> r;

			int a = center.first - start.first;
			int b = center.second - start.second;
			int c = center.first - end.first;
			int d = center.second - end.second;

			// 이탈
			if(a * a + b * b < r * r && c * c + d * d > r * r) cnt++;
			
			// 진입
			if(a * a + b * b > r * r && c * c + d * d < r * r) cnt++;
		}

		cout << cnt << "\n";
	}

	return 0;
}
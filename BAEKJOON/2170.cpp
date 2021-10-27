#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin >> n;
	vector<pair<int, int> > lines(n);
	for(int i = 0 ; i < n ; i++) {
		cin >> lines[i].first >> lines[i].second;
	}

	sort(lines.begin(), lines.end());

	int sum = 0;
	int left = -1000000001, right = -1000000001;
	for(auto line : lines) {
		if(right < line.first) {
			left = line.first;
			right = line.second;

			sum += right - left;
		}
		else if(right < line.second) {
			left = right;
			right = line.second;

			sum += right - left;
		}
	}

	cout << sum;

	return 0;
}
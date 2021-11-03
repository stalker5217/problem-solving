#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<pair<int, int> > score(8);
	for(int i = 0 ; i < 8 ; i++) {
		cin >> score[i].first;
		score[i].second = i + 1;
	}

	sort(score.begin(), score.end(), [](auto a, auto b) {
		return a.first > b.first;
	});
	score.erase(score.begin() + 5, score.end());

	int sum = 0;
	for(auto cur : score) {
		sum += cur.first;
	}
	cout << sum << "\n";

	sort(score.begin(), score.end(), [](auto a, auto b) {
		return a.second < b.second;
	});
	
	for(auto cur : score) {
		cout << cur.second << " ";
	}

	return 0;
}
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<char> signs(n, 0);
	for(int i = 0 ; i < n ; i++) {
		cin >> signs[i];
	}

	function<bool (int, int, char)> isValid = [](int left, int right, char sign) {
		switch(sign) {
			case '<': return left < right;
			case '>': return left > right;
		}

		return false;
	};
	
	// Max value
	vector<int> maxArr;
	maxArr.push_back(9);
	for(int i = 0, cur = 8 ; i < n ; i++, cur--) {
		maxArr.push_back(cur);
		
		int tmp = i;
		while(tmp >= 0 && !isValid(maxArr[tmp], maxArr[tmp + 1], signs[tmp])) {
			swap(maxArr[tmp], maxArr[tmp + 1]);
			tmp--;
		}
	}

	for(int cur : maxArr) cout << cur;
	cout << "\n";

	// Min value
	vector<int> minArr;
	minArr.push_back(0);
	for(int i = 0, cur = 1 ; i < n ; i++, cur++) {
		minArr.push_back(cur);

		int tmp = i;
		while(tmp >= 0 && !isValid(minArr[tmp], minArr[tmp + 1], signs[tmp])) {
			swap(minArr[tmp], minArr[tmp + 1]);
			tmp--;
		}
	}

	for(int cur : minArr) cout << cur;
	cout << "\n";

	return 0;
}
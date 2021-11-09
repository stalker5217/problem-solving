#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, p; 
	cin >> n >> p;

	vector<int> pSet;
	pSet.push_back(n);

	while(true) {
		int next = 0;
	
		while(n > 0) {
			int remain = n % 10;
			n /= 10;

			int mul = 1;
			for(int i = 0 ; i < p ; i++) mul *= remain;
			next += mul;
		}

		auto findResult = find(pSet.begin(), pSet.end(), next);
		if(findResult != pSet.end()) {
			pSet.erase(findResult, pSet.end());
			break;
		}
		else {
			pSet.push_back(next);
			n = next;
		}
	}

	cout << pSet.size();

	return 0;
}
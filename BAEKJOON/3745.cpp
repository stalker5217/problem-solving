#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while(cin >> n) {
		vector<int> stock(n);
		for(int i = 0 ; i < n ; i++) cin >> stock[i];

		vector<int> lis;
		lis.push_back(0);
		for(int i = 0 ; i < n ; i++) {
			if(stock[i] > lis.back()) lis.push_back(stock[i]);
			else {
				int replaceIdx = lower_bound(lis.begin(), lis.end(), stock[i]) - lis.begin();
				lis[replaceIdx] = stock[i];
			}
		}

		cout << lis.size() - 1 << "\n";
	}
}
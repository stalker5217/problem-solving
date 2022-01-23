#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testCase; cin >> testCase;
	while(testCase--) {
		int n; cin >> n;
		vector<int> ports(n);
		for(int i = 0 ; i < n; i++) cin >> ports[i];

		vector<int> lis(1, 0);
		for(int port : ports) {
			if(port > lis.back()) lis.push_back(port);
			else {
				int replaceIdx = lower_bound(lis.begin(), lis.end(), port) - lis.begin();
				lis[replaceIdx] = port;
			}
		}

		cout << lis.size() - 1 << "\n";
	}

	return 0;
}
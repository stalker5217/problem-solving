#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n; cin >> n;
	vector<int> ports(n);
	for(int i = 0 ; i < n ; i++) cin >> ports[i];
	
	vector<int> lis;
	lis.push_back(0);
	for(int port : ports) {
		if(port > lis.back()) lis.push_back(port);
		else {
			int idx = lower_bound(lis.begin(), lis.end(), port) - lis.begin();
			lis[idx] = port;
		}
	}

	cout << lis.size() - 1;

	return 0;
}
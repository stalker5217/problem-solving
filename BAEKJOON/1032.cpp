#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<string> strs(n);
	for(int i = 0 ; i < n ; i++) cin >> strs[i];

	for(int i = 0 ; i < strs[0].size() ; i++) {
		char cur = strs[0][i];
		bool allSame = true;
		for(int j = 1 ; j < n ; j++) {
			if(cur != strs[j][i]) {
				allSame = false;
				break;
			}
		}

		if(allSame) cout << cur;
		else cout << "?";
	}
}
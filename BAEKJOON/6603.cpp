#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	while(1) {
		int n; cin >> n;
		if(!n) break;
		
		vector<int> arr(n);
		for(int i = 0 ; i < n ; i++) cin >> arr[i];

		vector<int> pick;
		function<void (vector<int>, vector<int>, int, int)> combination = [&](vector<int> arr, vector<int> picked, int k, int curPos) {
			if(k == 0) {
				for(auto cur : picked) cout << cur << " ";
				cout << "\n";

				return;
			}

			for(int i = curPos ; i <= arr.size() - k ; i++) {
				picked.push_back(arr[i]);
				combination(arr, picked, k - 1, i + 1);
				picked.pop_back();
			}
		};
		
		combination(arr, pick, 6, 0);
		cout << "\n";
	}

    return 0;
}
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	function<int (int, int)> gcd = [&](int a, int b) {
		if(b == 0) return a;
		return gcd(b, a % b);
	};

	int testCase; cin >> testCase;
	while(testCase--) {
		int n; cin >> n;
		vector<int> arr(n);
		for(int i = 0 ; i < n ; i++) cin >> arr[i];
		
		long long sum = 0;
		for(int i = 0 ; i < arr.size() ; i++) {
			for(int j = i + 1 ; j < arr.size() ; j++) {
				if(arr[i] < arr[j]) sum += gcd(arr[j], arr[i]);
				else sum += gcd(arr[i], arr[j]);
			}
		}

		cout << sum << "\n";
	}
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<bool> isPrime(100'000'001, true);
	isPrime[0] = false; isPrime[1] = false;
	for(int i = 2 ; i <= 10'000 ; i++) {
		if(isPrime[i]) {
			for(int j = i * i ; j <= 100'000'000 ; j += i) {
				isPrime[j] = false;
			}
		}
	}

	while(true) {
		int n; cin >> n;
		if(n == 0) break;

		for(int i = 3 ; i <= n / 2 ; i += 2) {
			if(isPrime[i] && isPrime[n - i]) {
				cout << n << " = " << i << " + " << n - i << "\n";
				break;
			}
		}
	}

	return 0;
}
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
	if(b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long a, b;
	cin >> a >> b;
	if(a < b) swap(a, b);

	long long result = gcd(a, b);
	while(result--) cout << 1;

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

#define Prime 1234567891

typedef long long ll;

using namespace std;

ll power(ll x, ll y) {
	ll ret = 1;

	while (y > 0) {
		if (y % 2 == 1) {
			ret *= x;
			ret %= Prime;
		}

		x *= x;
		x %= Prime;
		y /= 2;
	}

	return ret;
}

ll fac[1000001];
ll inv[1000001];

int main(){
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	fac[1] = 1;
	for (int i = 2; i <= 1000000; i++)
		fac[i] = (fac[i - 1] * i) % Prime;
	inv[1000000] = power(fac[1000000], Prime - 2); 
	for (int i = 1000000 - 1; i > 0; i--)
		inv[i] = (inv[i + 1] * (i + 1)) % Prime;

	for (int test_case = 1; test_case <= T; ++test_case) {
		int N, R;
		cin >> N >> R;

		ll result = (fac[N] * inv[N - R]) % Prime;
		result = (result * inv[R]) % Prime;
		cout << "#" << test_case << " " << result << "\n";
	}

	return 0;
}
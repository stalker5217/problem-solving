#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);

	long long a, b;
	cin >> a >> b;

	if (a > b) {
		swap(a, b);
	}
	if (b - a <= 1) {
		cout << "0\n";
	}
	else {
		cout << b - a - 1 << "\n";
		for (long long i = a + 1; i < b; i++) {
			cout << i << " ";
		}
	}
	

	return 0;
}
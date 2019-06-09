#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


int main(){
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		int d, h, m;
		cin >> d >> h >> m;

		d -= 11;
		if (d < 0) {
			cout << "#" << test_case << " " << -1 << "\n";
			continue;
		}

		h -= 11;
		if (d == 0 && h < 0) {
			cout << "#" << test_case << " " << -1 << "\n";
			continue;
		}

		m -= 11;
		if (d == 0 && h == 0 && m < 0) {
			cout << "#" << test_case << " " << -1 << "\n";
			continue;
		}

		int ret = 0;
		if (m < 0) {
			m += 60;
			h -= 1;

			ret += m;
		}
		else {
			ret += m;
		}

		if (h < 0) {
			h += 24;
			d -= 1;

			ret += h * 60;
		}
		else {
			ret += h * 60;
		}

		ret += d * 1440;

		cout << "#" << test_case << " " << ret << "\n";
	}

	return 0;
}
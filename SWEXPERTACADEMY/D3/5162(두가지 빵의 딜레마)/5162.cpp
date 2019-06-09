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
		int a, b, c;
		cin >> a >> b >> c;

		int choice = (a <= b) ? a : b;
		int ret = c / choice;
		cout << "#" << test_case << " " << ret << "\n";
	}

	return 0;
}
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
		int N;
		cin >> N;

		vector<int> hay;
		int sum = 0;
		for (int i = 0; i < N; ++i) {
			int temp;
			cin >> temp;
			hay.push_back(temp);
			sum += temp;
		}

		int org = sum / N;
		int ret = 0;
		for (int i = 0; i < N; ++i) {
			int cnt = org - hay[i];
			if (cnt < 0)
				cnt *= -1;

			ret += cnt;
		}
		ret /= 2;
		cout << "#" << test_case << " " << ret << "\n";
	}

	return 0;
}
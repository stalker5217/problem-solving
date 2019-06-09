#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> list;
vector<int> choice;
vector<int> result;

void comb(int offset, int remain) {
	if (remain == 0) {
		int sum = 0;
		for (int i = 0; i < choice.size(); ++i) {
			sum += choice[i];
		}
		
		result.push_back(sum);
	}

	else {
		for (int i = offset; i <= list.size() - remain ; ++i) {
			choice.push_back(list[i]);
			comb(i + 1, remain - 1);
			choice.pop_back();
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		list.clear();
		choice.clear();
		result.clear();

		for (int i = 0; i < 7; i++) {
			int temp;
			cin >> temp;
			list.push_back(temp);
		}

		comb(0, 3);
		sort(result.begin(), result.end(), greater<int>());

		int ret;
		int cnt = 1;
		int before = result[0];
		for (int i = 1; i < result.size(); i++) {
			int cur = result[i];

			if (before == cur)
				continue;
			else {
				cnt++;
				before = cur;
				if (cnt == 5) {
					ret = cur;
					break;
				}
					
			}
		}
		cout << "#" << test_case << " " << ret << "\n";
	}

	return 0;
}
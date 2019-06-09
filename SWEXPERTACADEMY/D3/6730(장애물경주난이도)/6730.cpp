#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		vector<int> mheight;
		vector<int> up;
		vector<int> down;

		int N;
		cin >> N;

		for (int i = 0; i < N; ++i) {
			int temp;
			cin >> temp;
			mheight.push_back(temp);
		}

		//cout << "done read\n";

		for (int i = 0; i < mheight.size() - 1; ++i) {
			int diff = mheight[i + 1] - mheight[i];
			if (diff >= 0) {
				up.push_back(diff);
			}
			else {
				diff = -diff;
				down.push_back(diff);
			}
		}

		//cout << "done push\n";

		int upMax = 0;
		int downMax = 0;

		for (int i = 0; i < up.size(); ++i) {
			if (upMax < up[i])
				upMax = up[i];
		}

		for (int i = 0; i < down.size(); ++i) {
			if (downMax < down[i])
				downMax = down[i];

		}

		cout << "#" << test_case << " " << upMax << " " << downMax << "\n";
	}

	return 0;
}
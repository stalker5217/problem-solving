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
		int a, b;
		
		cin >> a >> b;
		pair<int, int> lowerLeft = make_pair(a, b);

		cin >> a >> b;
		pair<int, int> upperRight = make_pair(a, b);

		int num;
		cin >> num;

		int outer = 0;
		int inner = 0;
		int on = 0;

		for (int i = 0; i < num; ++i) {
			int x, y;
			cin >> x >> y;

			if (x < lowerLeft.first || x > upperRight.first || y < lowerLeft.second || y > upperRight.second) {
				outer++;
			}

			else if(x == lowerLeft.first || x == upperRight.first || y == lowerLeft.second || y == upperRight.second) {
				on++;
			}

			else {
				inner++;
			}
		}

		cout << "#" << test_case << " " << inner << " " << on << " " << outer << "\n";
	}

	return 0;
}
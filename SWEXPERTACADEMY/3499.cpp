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
		int n;
		cin >> n;

		vector<string> arr;
		for (int i = 0; i < n; ++i) {
			string temp;
			cin >> temp;
			arr.push_back(temp);
		}

		vector<int> index;
		int end;
		if (n % 2 == 0)
			end = n / 2;
		else
			end = n / 2 + 1;

		for (int i = 0; i < n / 2; ++i) {
			index.push_back(i);
			index.push_back(i + end);
		}

		if (n % 2 == 1)
			index.push_back(end - 1);


		cout << "#" << test_case << " ";
		for (int i = 0; i < n; i++) {
			cout << arr[index[i]] << " ";
		}
		cout << "\n";
	}

	return 0;
}
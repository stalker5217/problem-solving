#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);

	int test_case;
	cin >> test_case;

	for (int t = 0; t < test_case; t++) {
		int n, k;
		cin >> n >> k;

		vector<int> arr;
		
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			arr.push_back(temp);
		}
		
		sort(arr.begin(), arr.end(), greater<int>());

		int sum = 0;
		for (int i = 0; i < k; i++) {
			sum += arr[i];
		}

		cout << "#" << t + 1 << " " << sum << endl;
	}

	return 0;
}
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

		bool * isSubmit;
		isSubmit = new bool[n+1];
		memset(isSubmit, false, sizeof(bool) * n+1);

		for (int i = 0; i < k; i++) {
			int temp;
			cin >> temp;
			isSubmit[temp] = true;
		}
		
		cout << "#" << t + 1 << " ";
		for (int i = 1; i <= n; i++) {
			if (isSubmit[i] == false)
				cout << i << " ";
		}
		cout << "\n";
		
	}

	return 0;
}
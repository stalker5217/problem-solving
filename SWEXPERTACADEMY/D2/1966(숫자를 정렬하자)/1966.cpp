#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;

		vector<int> vt;

		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			vt.push_back(temp);
		}

		sort(vt.begin(), vt.end());

		cout << "#" << test_case << " ";
		for (int i = 0; i < n; i++) {
			cout << vt[i];
			if (i < n - 1)
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}
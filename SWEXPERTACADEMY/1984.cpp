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
		vector<int> arr;

		for (int i = 0; i < 10; i++) {
			int temp;
			cin >> temp;
			arr.push_back(temp);
		}

		sort(arr.begin(), arr.end());

		int sum = 0;
		for (int i = 1; i < 9; i++)
			sum += arr[i];

		double dAvg = (double)sum / 8;
		dAvg += 0.5;
		int avg = (int)dAvg;

		cout << "#" << test_case << " " << avg << endl;
	}

	return 0;
}
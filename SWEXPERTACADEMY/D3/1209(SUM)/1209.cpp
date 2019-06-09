#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <stack>

using namespace std;


int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	//int test_case;
	//cin >> test_case;

	for (int t = 1; t <= 10; t++) {
		int test;
		cin >> test;
		
		int arr[100][100];
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				cin >> arr[i][j];

		int max = -1;

		// 대각선
		int sum = 0;
		for (int i = 0; i < 100; i++) {
			sum += arr[i][i];
		}
		if (sum > max)
			sum = max;

		// 대각선2
		sum = 0;
		for (int i = 0; i < 100; i++) {
			sum += arr[99 - i][i];
		}
		if (sum > max)
			sum = max;

		// 가로
		for (int i = 0; i < 100; i++) {
			sum = 0;
			for (int j = 0; j < 100; j++) {
				sum += arr[i][j];
			}
			if (sum > max)
				sum = max;
		}

		for (int j = 0; j < 100; j++) {
			sum = 0;
			for (int i = 0; i < 100; i++) {
				sum += arr[i][j];
			}
			if (sum > max)
				sum = max;
		}

		cout << "#" << test << " " << max << endl;
	}

	
	return 0;
}
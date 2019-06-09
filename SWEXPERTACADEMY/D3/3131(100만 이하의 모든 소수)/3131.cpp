#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <stack>

using namespace std;


int main(int argc, char** argv)
{
	//freopen("input.txt", "r", stdin);
	//int test_case;
	//cin >> test_case;

	/*
	for (int i = 2; i <= 1000000; i++) {
		bool isPrime = true;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0)
				isPrime = false;
		}
		if (isPrime)
			printf("%d ", i);
	}
	*/

	bool * arr = new bool[1000000];
	memset(arr, 1, 1000000 * sizeof(bool));

	for (int i = 2; i <= 1000; i++) {
		if (arr[i]) {
			int x = 2*i;
			while (true) {
				arr[x] = false;
				x += i;
				if (x > 1000000)
					break;
			}
		}
	}

	for (int i = 2; i <= 1000000; i++) {
		if (arr[i]) {
			printf("%d ", i);
		}
	}
	
	delete[] arr;
	
	return 0;
}
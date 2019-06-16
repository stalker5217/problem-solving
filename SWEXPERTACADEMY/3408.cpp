#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
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
	int test_case;
	cin >> test_case;

	for (int t = 1; t <= test_case; t++) {
		unsigned long long n;
		cin >> n;

		unsigned long long aa = 0;
		unsigned long long bb = 0;
		unsigned long long cc = 0;

		aa = n * (n + 1) / 2;
		bb = n * (n + 1) - n;
		cc = n * (n + 1);
		printf("#%d %llu %llu %llu\n", t, aa, bb, cc);
	}

	return 0;
}
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
	//freopen("input.txt", "r", stdin);

	int test_case;
	cin >> test_case;

	for (int t = 0; t < test_case; t++) {
		int N;
		cin >> N;
		long long tri[101];

		tri[1] = 1;
		tri[2] = 1;
		tri[3] = 1;
		tri[4] = 2;
		tri[5] = 2;

		for (int i = 6; i <= 100; ++i)
			tri[i] = tri[i - 1] + tri[i - 5];

		cout << "#" << t + 1 << " " << tri[N] << "\n";
	}

	return 0;
}
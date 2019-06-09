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
		int sum = 0;
		for (int i = 0; i < 5; i++) {
			int temp;
			cin >> temp;
			if (temp < 40)
				sum += 40;
			else
				sum += temp;
		}

		cout << "#" << t + 1 << " " << sum/5 << "\n";
	}

	return 0;
}
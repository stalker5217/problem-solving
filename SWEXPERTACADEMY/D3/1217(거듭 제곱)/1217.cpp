#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int recursive(int n, int m) {
	if (m == 1)
		return n;
	else
		return n * recursive(n, m - 1);
}


int main(int argc, char** argv)
{
	//freopen("input.txt", "r", stdin);
	//int test_case;
	//cin >> test_case;

	for (int t = 1; t <= 10; t++) {
		int n, m;
		cin >> n >> m;

		int result = recursive(n, m);
		cout << "#" << t << " " << result << endl;
	}


	return 0;
}
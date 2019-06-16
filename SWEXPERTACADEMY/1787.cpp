#define _CRT_SECURE_NO_WARNINGS

#include <iostream>


using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n1, n2;

		cin >> n1 >> n2;

		cout << n1 * n2 << endl;
	}
	return 0;
}



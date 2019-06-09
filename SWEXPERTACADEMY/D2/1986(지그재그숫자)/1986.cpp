#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <list>

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

		cout << "#" << test_case << " ";

		n += 1;

		if (n % 2 == 0)
			cout << n / 2;
		else
			cout << -(n / 2);

		cout << endl;
	}
	return 0;
}
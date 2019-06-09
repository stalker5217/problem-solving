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
		cout << "#" << test_case << endl;

		int money;
		cin >> money;

		int result;

		result = money / 50000;
		cout << result << " ";
		money -= result * 50000;

		result = money / 10000;
		cout << result << " ";
		money -= result * 10000;

		result = money / 5000;
		cout << result << " ";
		money -= result * 5000;

		result = money / 1000;
		cout << result << " ";
		money -= result * 1000;

		result = money / 500;
		cout << result << " ";
		money -= result * 500;

		result = money / 100;
		cout << result << " ";
		money -= result * 100;

		result = money / 50;
		cout << result << " ";
		money -= result * 50;

		result = money / 10;
		cout << result << " " << endl;
	}
	return 0;
}
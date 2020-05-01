#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int n, k;
	cin >> n >> k;

	int result = 1;
	for (int i = 1; i <= k; i++) {
		result *= n + 1 - i;
		result /= i;
	}

	cout << result << endl;

	return 0;
}
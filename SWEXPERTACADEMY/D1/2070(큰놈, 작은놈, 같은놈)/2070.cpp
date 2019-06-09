#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main() {
	int testCase;
	cin >> testCase;

	for (int t = 0; t < testCase; t++) {
		int a, b;
		char result;
		cin >> a >> b;

		if (a > b)
			result = '>';
		else if (a == b)
			result = '=';
		else
			result = '<';


		cout << "#" << t + 1 << " " << result << endl;
	}
}
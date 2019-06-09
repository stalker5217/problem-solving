#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;


int main(int argc, char** argv)
{
	int t;
	cin >> t;

	for (int test_case = 1; test_case <= t; ++test_case) {
		int distance;
		int a, b;
		int fly;

		cin >> distance >> a >> b >> fly;

		double time = (double)distance / (a + b);
		double result = time * fly;

		cout << fixed;
		cout.precision(10);
		cout << "#" << test_case << " " << result << endl;
	}

	return 0;
}
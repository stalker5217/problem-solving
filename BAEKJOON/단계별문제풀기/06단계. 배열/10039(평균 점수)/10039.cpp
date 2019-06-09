#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int temp;
		cin >> temp;

		if (temp < 40)
			sum += 40;
		else
			sum += temp;
	}

	cout << sum / 5 << endl;

	return 0;
}
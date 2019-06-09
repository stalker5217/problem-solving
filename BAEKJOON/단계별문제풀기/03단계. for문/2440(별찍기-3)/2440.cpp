#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);

	int r;
	cin >> r;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r-i; j++)
			cout << "*";
		cout << endl;
	}
}
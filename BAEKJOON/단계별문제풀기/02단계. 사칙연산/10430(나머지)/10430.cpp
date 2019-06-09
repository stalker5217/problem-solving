#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);

	int a, b, c;
	cin >> a >> b >> c;

	cout << (a + b)%c << endl;
	cout << (a%c + b%c)%c << endl;
	cout << (a * b)%c << endl;
	cout << (a%c * b%c)%c << endl;
	
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);

	int r;
	cin >> r;
	for (int i = r; i > 0; i--) {
		printf("%d\n", i);
	}
}
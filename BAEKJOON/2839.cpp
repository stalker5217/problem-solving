#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);

	int total;
	cin >> total;
	
	int min = 100000000;
	int a, b; // 5키로, 3키로
	
	for (int i = 0; i <= total / 5; i++) {
		a = i;
		if ((total - i * 5) % 3 == 0) {
			b = (total - i * 5) / 3;
			if (min > a + b)
				min = a + b;
		}
	}
	if (min == 100000000)
		cout << "-1" << endl;
	else
		cout << min << endl;
}
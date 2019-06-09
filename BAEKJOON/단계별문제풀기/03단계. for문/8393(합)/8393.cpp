#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);

	int n;
	cin >> n;
	int sum = 0;

	for (int i = 1; i <= n; i++)
		sum += i;

	printf("%d\n", sum);

	return 0;
}
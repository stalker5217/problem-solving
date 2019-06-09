#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);

	int n;
	int sum = 0;

	scanf("%d", &n);
	getchar();
	for (int i = 1; i <= n; i++) {
		char ch = getchar();
		sum += ch - '0';
	}
		
	printf("%d\n", sum);

	return 0;
}
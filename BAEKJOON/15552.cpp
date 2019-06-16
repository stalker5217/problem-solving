#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main() {
	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
	
	return 0;
}
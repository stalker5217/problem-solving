#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int testCase;
	int i;

	int a, b;

	scanf("%d", &testCase);

	for (i = 0; i < testCase; i++) {
		scanf("%d %d", &a, &b);
		printf("#%d ", i + 1);
		printf("%d %d\n", a / b, a%b);
	}
}
#include <stdio.h>

int main() {
	int testCase;
	int i;
	int a = 1;

	scanf("%d", &testCase);

	for (i = 0; i < testCase; i++) {
		printf("%d ", a);
		a *= 2;
	}
	printf("%d", a);
	return 0;
}
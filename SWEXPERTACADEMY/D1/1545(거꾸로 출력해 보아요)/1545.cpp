#include <stdio.h>

int main() {
	int n;
	int i;

	scanf("%d", &n);

	for (i = n; i > 0; i--)
		printf("%d ", i);
	printf("0");

	return 0;
}
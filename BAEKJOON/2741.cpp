#include <stdio.h>

int main() {
	int size;
	int i;

	scanf("%d", &size);

	for (i = 0; i < size; i++) {
		printf("%d\n", i + 1);
	}

	return 0;
}
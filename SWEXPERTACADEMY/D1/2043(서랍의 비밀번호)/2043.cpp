#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	int answer, start;
	int cnt = 0;

	scanf("%d %d", &answer, &start);

	while (true) {
		cnt += 1;

		if (answer == start) {
			break;
		}

		else {
			start += 1;
		}
	}

	printf("%d\n", cnt);
}
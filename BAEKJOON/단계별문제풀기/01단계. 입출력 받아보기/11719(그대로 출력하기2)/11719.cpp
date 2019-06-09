#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	freopen("input.txt", "r", stdin);
	
	while (true) {
		char ch;
		ch = getchar();
		if (ch == EOF)
			break;

		printf("%c", ch);
	}

	return 0;
}
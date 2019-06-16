#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);

	int cnt = 0;
	while (true) {
		char ch = getchar();
		if (ch == EOF)
			break;
		putchar(ch);
		cnt++;

		if (cnt % 10 == 0)
			printf("\n");
	}
	
	return 0;
}
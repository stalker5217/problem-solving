#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main() {
	int testCase, t;
	int year, month, day;
	int temp;

	scanf("%d", &testCase);

	for (t = 0; t < testCase; t++) {
		scanf("%d", &temp);

		printf("#%d ", t + 1);

		day = temp % 100;
		temp -= day;

		if (day <= 0 || day >= 32) {
			printf("-1\n");
			continue;
		}

		month = temp % 10000;
		month /= 100;
		temp -= month;

		if (month <= 0 || month >= 13) {
			printf("-1\n");
			continue;
		}


		if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day == 31) {
				printf("-1\n");
				continue;
			}
		}

		else if (month == 2) {
			if (day == 29 || day == 30 || day == 31) {
				printf("-1\n");
				continue;
			}
		}

		year = temp / 10000;

		printf("%04d/%02d/%02d\n", year, month, day);
	}


}
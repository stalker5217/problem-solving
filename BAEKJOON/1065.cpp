#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>


int main(int argc, char** argv)
{
	int num;
	int cnt = 0;
	scanf("%d", &num);
	if (num < 100) {
		cnt = num;
	}

	else {
		cnt = 99;
		for (int i = 100; i <= num; i++) {
			int first, second, third;
			int temp = i;
			third = i % 10;
			temp /= 10;

			second = temp % 10;
			temp /= 10;

			first = temp % 10;

			printf("%d %d %d", first, second, third);
			if (third - second == second - first) {
				cnt++;
				printf(" Yes!!");
			}
			printf("\n");
		}
	}

	printf("%d", cnt);

	return 0;
}
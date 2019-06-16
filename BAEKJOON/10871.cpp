#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int main(int argc, char** argv)
{
	int n, sample;
	scanf("%d %d", &n, &sample);

	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);

		if (temp < sample)
			printf("%d ", temp);
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main() {
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case) {
		int total;
		scanf("%d", &total);

		int sum = 0;
		double avg;
		int stu[1000];
		for (int i = 0; i < total; i++) {
			scanf("%d", &stu[i]);
			sum += stu[i];
		}
		avg = (double)sum / (double)total;

		int good = 0;
		for (int i = 0; i < total; i++) {
			if ((double)stu[i] > avg)
				good++;
		}

		printf("%.3f%%\n", (double)good / total * 100);
	}
	
	return 0;
}
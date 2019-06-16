#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

using namespace std;

enum {
	SUN = 0, MON, TUE, WED, THU, FRI, SAT
};

int main() {
	freopen("input.txt", "r", stdin);

	int m,d;
	cin >> m >> d;
	
	int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int total = 0;

	for (int i = 1; i < m; i++) {
		total += month[i];
	}

	total += d;

	switch(total % 7) {
	case SUN:
		printf("SUN\n");
		break;
	case MON:
		printf("MON\n");
		break;
	case TUE:
		printf("TUE\n");
		break;
	case WED:
		printf("WED\n");
		break;
	case THU:
		printf("THU\n");
		break;
	case FRI:
		printf("FRI\n");
		break;
	case SAT:
		printf("SAT\n");
		break;

	}

	return 0;
}
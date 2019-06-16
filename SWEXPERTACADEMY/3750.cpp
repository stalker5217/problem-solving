#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int getSum(long long num) {
	if (num / 10 == 0)
		return num;

	else {
		long long sum = 0;
		
		while (true) {
			sum += num % 10;
			num /= 10;
			if (num == 0) {
				return getSum(sum);
			}
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);

	int T;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case) {
		long long temp;
		scanf("%lld", &temp);

		int ret = getSum(temp);
		printf("#%d %d\n", test_case, ret);
	}

	return 0;
}
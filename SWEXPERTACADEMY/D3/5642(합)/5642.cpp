#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


int main(){
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		int N, K;
		cin >> N >> K;

		int cost[1000];
		double min = 100;

		for (int i = 0; i < N; ++i) {
			cin >> cost[i];
		}

		for (int i = K; i <= N; ++i) {
			for (int j = 0; j <= N - i; ++j) {
				double avg;
				int sum = 0;
				for (int k = j; k < j + i; ++k) {
					sum += cost[k];
				}
				avg = (double)sum / i;

				if (avg < min) {
					min = avg;
				}
			}
		}
		
		printf("%.11f\n", min);
	}

	return 0;
}
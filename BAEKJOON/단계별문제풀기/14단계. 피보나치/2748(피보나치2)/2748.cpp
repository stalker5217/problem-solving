#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

using namespace std;


int main() {
	freopen("input.txt", "r", stdin);

	int n;
	cin >> n;
	
	long long* fibo = new long long[n + 1];
	fibo[0] = 0;
	fibo[1] = 1;

	for (int i = 2; i <= n; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		
	printf("%lld\n", fibo[n]);

	delete[] fibo;

	return 0;
}
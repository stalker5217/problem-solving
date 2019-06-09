#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void nqueen(int);
bool isPromising(int);

int N;
int col[11] = { 0, };
int cnt = 0;

int main(){
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;


	for (int test_case = 1; test_case <= T; ++test_case) {
		cnt = 0;
		cin >> N;
		for (int i = 0; i <= 10; ++i) col[i] = 0;
		nqueen(0);
		cout << "#" << test_case << " " << cnt << "\n";
	}

	return 0;
}

bool isPromising(int i) {
	bool promising = true;
	
	for (int k = 1; k < i && promising; ++k) {
		if (col[i] == col[k] || abs(col[i] - col[k]) == abs(i - k))
			promising = false;
	}

	return promising;
}

void nqueen(int i) {
	if (isPromising(i)) {
		if (i == N) {
			cnt++;
			return;
		}

		else {
			for (int j = 1; j <= N; ++j) {
				col[i + 1] = j;
				nqueen(i + 1);
			}
		}
	}
}
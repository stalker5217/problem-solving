#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
	bool result = true;
	for (int i = 2; i <= n / 2; i++) {
		if (n%i == 0) {
			result = false;
			break;
		}

	}

	return result;
}

int main(int argc, char** argv)
{
	//freopen("input.txt", "r", stdin);
	
	int test_case;
	cin >> test_case;

	for (int t = 0; t < test_case; t++) {
		int n;
		cin >> n;
		
		int callZero[41];
		int callOne[41];

		callZero[0] = 1;
		callZero[1] = 0;

		callOne[0] = 0;
		callOne[1] = 1;

		for (int i = 2; i <= n; i++) {
			callZero[i] = callZero[i - 1] + callZero[i - 2];
			callOne[i] = callOne[i - 1] + callOne[i - 2];
		}

		cout << callZero[n] << " " << callOne[n] << endl;

	}
	return 0;
}
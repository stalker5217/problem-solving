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
		int num;
		cin >> num;

		for (int i = num / 2; i >= 2; i--) {
			if (isPrime(i) && isPrime(num - i)) {
				cout << i << " " << num - i << endl;
				break;
			}
		}

	}
	return 0;
}
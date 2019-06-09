#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int n;
	cin >> n;

	int clap = 0;

	for (int i = 1; i <= n; i++) {
		int temp = i;
		while (true) {
			if (temp % 10 == 3 || temp % 10 == 6 || temp % 10 == 9)
				clap++;

			temp /= 10;

			if (temp == 0)
				break;
		}

		if (clap == 0)
			cout << i << " ";
		else {
			for (int j = 0; j < clap; j++)
				cout << "-";
			cout << " ";
			clap = 0;
		}
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int testCase;
	cin >> testCase;

	for (int t = 0; t < testCase; t++) {
		int people;
		cin >> people;

		int cnt = 0;
		int min = 100001;

		for (int i = 0; i < people; i++) {
			int temp;
			cin >> temp;
			temp = abs(temp);

			if (temp < min) {
				min = temp;
				cnt = 1;
			}

			else if (temp == min)
				cnt++;

		}

		cout << "#" << t + 1 << " " << min << " " << cnt << endl;
	}
}
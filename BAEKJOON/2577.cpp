#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


int main(int argc, char** argv)
{
	int a, b, c;
	cin >> a >> b >> c;

	int cnt[10] = { 0, };

	int value = a * b * c;
	while (true) {
		if (value / 10 == 0) {
			cnt[value % 10]++;
			break;
		}

		else {
			cnt[value % 10]++;
			value /= 10;
		}
			
	}
	
	for (int i = 0; i < 10; i++)
		cout << cnt[i] << endl;

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	
	
	for (int t = 0; t < 10; t++) {
		int cnt = 0;
		
		int test;
		cin >> test;
		
		char map[100][100];

		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				cin >> map[i][j];

		
		
		for (int len = 100; len >= 1; len--) {
			bool isPal = true;

			for (int i = 0; i < 100; i++) {
				for (int j = 0; j <= 100 - len; j++) {
					isPal = true;
					for (int k = 0; k < len / 2; k++) {
						if (map[i][j + k] != map[i][j + len - k - 1]) {
							isPal = false;
							break;
						}
					}
					if (isPal)
						break;
				}
				if (isPal)
					break;
			}

			if (isPal) {
				cout << "#" << t + 1 << " " << len << endl;
				break;
			}

			for (int j = 0; j < 100; j++) {
				for (int i = 0; i <= 100 - len; i++) {
					isPal = true;
					for (int k = 0; k < len / 2; k++) {
						if (map[i + k][j] != map[i + len - k - 1][j]) {
							isPal = false;
							break;
						}
					}
					if (isPal)
						break;
				}
				if (isPal)
					break;
			}
			
			if (isPal) {
				cout << "#" << t + 1 << " " << len << endl;
				break;
			}
		}
	}

	return 0;
}
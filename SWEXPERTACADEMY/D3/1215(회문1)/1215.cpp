#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	
	
	for (int t = 0; t < 10; t++) {
		int cnt = 0;
		
		int len;
		cin >> len;
		
		char map[8][8];

		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				cin >> map[i][j];

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j <= 8 - len; j++) {
				bool isPal = true;
				for (int k = 0; k < len / 2; k++) {
					if (map[i][j + k] != map[i][j + len - k - 1]) {
						isPal = false;
						break;
					}
				}
				if (isPal)
					cnt++;
			}
		}

		for (int j = 0; j < 8; j++) {
			for (int i = 0; i <= 8 - len; i++) {
				bool isPal = true;
				for (int k = 0; k < len / 2; k++) {
					if (map[i+k][j] != map[i + len - k - 1][j]) {
						isPal = false;
						break;
					}
				}
				if (isPal)
					cnt++;
			}
		}

		cout << "#" << t + 1 << " " << cnt << endl;
	}

	return 0;
}
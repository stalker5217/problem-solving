#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;


int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	//int test_case;
	//cin >> test_case;

	for (int t = 1; t <= 10; t++) {
		int width;
		cin >> width;
		
		int height[1000];
		int building[1000][255];

		for (int i = 0; i < width; i++) {
			cin >> height[i];
		}

		for (int i = 0; i < 1000; i++)
			for (int j = 0; j < 255; j++)
				building[i][j] = 0;

		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height[i]; j++)
				building[i][j] = 1;
		}

		int view = 0;
		for (int i = 2; i < width - 2; i++) {
			for (int j = 0; j < 255; j++) {
				if (building[i][j] == 1) {
					if (building[i - 1][j] == 0 && building[i - 2][j] == 0 && building[i + 1][j] == 0 && building[i + 2][j] == 0)
						view++;
				}
			}
		}
		cout << "#" << t << " " << view << endl;

	}

	
	return 0;
}
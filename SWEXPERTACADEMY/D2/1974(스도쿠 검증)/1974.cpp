#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;

	//  freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int sdoku[10][10];
		bool row[10][10] = { false, };
		bool col[10][10] = { false, };
		bool result = true;

		for (int i = 1; i <= 9; i++)
			for (int j = 1; j <= 9; j++)
				cin >> sdoku[i][j];


		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				if (row[i][sdoku[i][j]] == true) {
					result = false;
					break;
				}

				if (col[j][sdoku[i][j]] == true) {
					result = false;
					break;
				}

				row[i][sdoku[i][j]] = true;
				col[j][sdoku[i][j]] = true;

			}
		}

		bool *box;


		for (int i = 1; i <= 9; i += 3) {
			for (int j = 1; j <= 9; j += 3) {
				box = new bool[10];
				memset(box, 0, sizeof(bool) * 10);
				for (int k = 1; k <= 9; k++) {
					int x = (k - 1) / 3;
					int y = (k - 1) % 3;

					if (box[sdoku[i + x][j + y]] == true) {
						result = false;
						break;
					}
					box[sdoku[i + x][j + y]] = true;
				}

			}
		}


		//delete box;

		int a = result ? 1 : 0;
		cout << "#" << test_case << " " << a  << endl;
	}
	return 0;
}
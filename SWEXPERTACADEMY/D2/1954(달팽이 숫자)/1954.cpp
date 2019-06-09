#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << endl;

		int size;
		cin >> size;

		int ** arr = new int*[size + 2];
		for (int i = 0; i < size + 2; i++)
			arr[i] = new int[size + 2];

		for (int i = 0; i < size + 2; i++) {
			for (int j = 0; j < size + 2; j++) {
				if (i == 0 || i == size + 1 || j == 0 || j == size + 1)
					arr[i][j] = 1;
				else
					arr[i][j] = -1;
			}
		}
		int a = 1, b = 1;
		int da = 0, db = 1;
		for (int i = 0; i < size * size; i++) {
			arr[a][b] = i + 1;

			if (arr[a + da][b + db] > 0) {
				if (da == 0 && db == 1) {
					da = 1;
					db = 0;
				}

				else if (da == 1 && db == 0) {
					da = 0;
					db = -1;
				}

				else if (da == 0 && db == -1) {
					da = -1;
					db = 0;
				}

				else if (da == -1 && db == 0) {
					da = 0;
					db = 1;
				}
			}

			a += da;
			b += db;
		}


		for (int i = 1; i <= size; i++) {
			for (int j = 1; j <= size; j++) {
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}

		for (int i = 0; i < size + 2; i++)
			delete[] arr[i];
		delete[] arr;
	}
	return 0;
}
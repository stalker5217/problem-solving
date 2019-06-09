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
		int arr[7][7];
		int size;
		cin >> size;

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				cin >> arr[i][j];

		int rot1[7][7];
		int rot2[7][7];
		int rot3[7][7];

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++) {
				rot1[j][size - 1 - i] = arr[i][j];
				rot2[size - 1 - i][size - 1 - j] = arr[i][j];
				rot3[size - 1 - j][i] = arr[i][j];
			}

		cout << "#" << test_case << endl;

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << rot1[i][j];
			}
			cout << " ";
			for (int j = 0; j < size; j++) {
				cout << rot2[i][j];
			}
			cout << " ";
			for (int j = 0; j < size; j++) {
				cout << rot3[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
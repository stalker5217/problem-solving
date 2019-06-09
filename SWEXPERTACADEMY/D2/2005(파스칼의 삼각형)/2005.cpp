#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <map>

using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;


	int ** pTree;

	pTree = new int*[10];
	for (int i = 0; i < 10; i++)
		pTree[i] = new int[i + 1];

	pTree[0][0] = 1;

	for (int i = 1; i < 10; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				pTree[i][j] = 1;
			else
				pTree[i][j] = pTree[i - 1][j - 1] + pTree[i - 1][j];
		}
	}

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int level;
		cin >> level;

		cout << "#" << test_case << endl;
		for (int i = 0; i < level; i++) {
			for (int j = 0; j <= i; j++)
				cout << pTree[i][j] << " ";
			cout << endl;
		}
	}

	for (int i = 0; i < 10; i++)
		delete[] pTree[i];

	delete[] pTree;

	return 0;
}
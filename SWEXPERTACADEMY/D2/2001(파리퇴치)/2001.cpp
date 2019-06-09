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

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << " ";

		int arr[15][15];
		int N, M;

		cin >> N >> M;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> arr[i][j];

		int max = 0;

		for (int i = 0; i < N - M + 1; i++) {
			for (int j = 0; j < N - M + 1; j++) {

				int value = 0;
				for (int k = 0; k < M; k++)
					for (int l = 0; l < M; l++)
						value += arr[i + k][j + l];

				if (max < value)
					max = value;
			}
		}

		cout << max << endl;



	}

	return 0;
}
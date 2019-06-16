#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, K;
		cin >> N >> K;

		vector<int> arr;

		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			arr.push_back(temp);
		}

		sort(arr.begin(), arr.end());

		double score = 0;
		for (int i = N - K; i < N; i++)
			score = (score + arr[i]) / 2;

		printf("#%d %.6f\n", test_case, score);
	}
	return 0;
}
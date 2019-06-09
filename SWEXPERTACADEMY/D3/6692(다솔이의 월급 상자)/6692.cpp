#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;

		double expect = 0;
		for (int i = 0; i < N; i++) {
			double p;
			int x;
			cin >> p >> x;

			expect += p * x;
		}

		printf("#%d %.6f\n", test_case, expect);

	}
	return 0;
}
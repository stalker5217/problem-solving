#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <list>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;

		list<long> ls;

		for (int i = 0; i < n; i++) {
			long temp;
			cin >> temp;
			ls.push_front(temp);
		}

		list<long>::iterator iter = ls.begin();

		long max = -1;
		long pay = 0;
		long cnt = 0;
		long earn = 0;

		while (iter != ls.end()) {
			if (max < *iter) {
				earn += cnt * max - pay;

				max = *iter;
				cnt = 0;
				pay = 0;
			}

			else {
				cnt++;
				pay += *iter;
			}

			iter++;
		}

		earn += cnt * max - pay;

		cout << "#" << test_case << " " << earn << endl;
	}
	return 0;
}
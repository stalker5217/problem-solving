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
		int m1, m2;
		int s1, s2;

		int m = 0, s = 0;

		cin >> m1 >> s1 >> m2 >> s2;

		s = (s1 + s2) % 60;
		m = (s1 + s2) / 60;

		m += m1 + m2;
		if (m % 12 != 0)
			m %= 12;
		else
			m = 12;

		cout << "#" << test_case << " " << m << " " << s << endl;

	}
	return 0;
}
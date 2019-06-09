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
		string str;
		cin >> str;

		int len = 1;

		bool result;
		while (true) {
			for (int i = 0; i < len; i++) {
				if (str[i] == str[len + i])
					result = true;
				else {
					result = false;
					break;
				}
			}

			if (result == true)
				break;
			else
				len++;
		}

		cout << "#" << test_case << " " << len << endl;
	}

	return 0;
}
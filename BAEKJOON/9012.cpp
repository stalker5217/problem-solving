#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;


int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	int test_case;
	cin >> test_case;

	for (int t = 0; t < test_case; t++) {
		string str;
		cin >> str;
		bool isRight = true;

		int left = 0;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(')
				left++;
			else if (str[i] == ')') {
				if (left <= 0) {
					isRight = false;
					break;
				}
				else
					left--;
			}
		}

		if (left == 0 && isRight)
			cout << "YES\n";
		else
			cout << "NO\n";
			
	}

	return 0;
}
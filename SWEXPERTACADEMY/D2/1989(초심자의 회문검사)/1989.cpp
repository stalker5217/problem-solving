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
		//      cout << str << endl;

		bool isPalindrome = true;
		int front = 0;
		int back = str.length() - 1;

		while (1) {

			if (front == back || front - back == -1)
				break;

			else {
				if (str[front] != str[back]) {
					isPalindrome = false;
					break;
				}
				front++;
				back--;
			}
		}


		cout << "#" << test_case << " ";
		int result = isPalindrome ? 1 : 0;
		cout << result << endl;

	}
	return 0;
}
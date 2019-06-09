#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;


int main(int argc, char** argv)
{
	int t;
	cin >> t;

	int cnt = 0;

	for (int test_case = 0; test_case < t; test_case++) {
		string str;
		cin >> str;
		
		bool isGroup[26];

		for (int i = 0; i < 26; i++)
			isGroup[i] = false;

		int index = 0;
		bool result = true;

		while (true) {
			char curChar = str[index];

			if (index + 1 >= str.length()) {
				if (isGroup[curChar - 'a'] == true)
					result = false;
				break;
			}

			else if (curChar == str[index + 1]) {
				index++;
			}

			else {
				if (isGroup[curChar - 'a'] == true) {
					result = false;
					break;
				}
				else
					isGroup[curChar - 'a'] = true;
				
				index++;
			}
		}

		if(result == true)
			cnt++;
	}
	
	cout << cnt;

	return 0;
}
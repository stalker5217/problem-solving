#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;


int main(int argc, char** argv)
{
	string str;
	cin >> str;

	int cnt = 0;

	for (int index = 0; index < str.length(); index++) {
		if (index == str.length() - 1) {
			cnt++;
			break;
		}

		if (str[index] == 'c') {
			if (str[index + 1] == '=' || str[index + 1] == '-') {
				index++;
				cnt++;
			}
			else
				cnt++;
		}

		else if (str[index] == 'd') {
			if (str[index + 1] == '-') {
				index++;
				cnt++;
			}
			else if (index < str.length() - 2 && str[index + 1] == 'z' && str[index + 2] == '=') {
				index += 2;
				cnt++;
			}
			else
				cnt++;
		}

		else if (str[index] == 'l' && str[index + 1] == 'j') {
			index++;
			cnt++;
		}

		else if (str[index] == 'n' && str[index + 1] == 'j') {
			index++;
			cnt++;
		}

		else if (str[index] == 's' && str[index + 1] == '=') {
			index++;
			cnt++;
		}

		else if (str[index] == 'z' && str[index + 1] == '=') {
			index++;
			cnt++;
		}

		else
			cnt++;
	}

	cout << cnt;

	return 0;
}
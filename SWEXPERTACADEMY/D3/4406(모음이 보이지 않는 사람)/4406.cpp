#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	cin >> test_case;

	for (int t = 0; t < test_case; t++) {
		cout << "#" << t + 1 << " ";

		string str;
		cin >> str;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == 'a' || str[i] == 'i' || str[i] == 'u' || str[i] == 'o' || str[i] == 'e');
			else {
				cout << str[i];
			}
		}

		cout << endl;
	}


	return 0;
}
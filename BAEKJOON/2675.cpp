#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	cin >> test_case;

	for (int t = 0; t < test_case; t++) {
		int repeat;
		cin >> repeat;
		getchar();
		string str;
		cin >> str;

		for (int i = 0; i < str.length(); i++) {
			for (int j = 0; j < repeat; j++) {
				cout << str[i];
			}
		}
		cout << endl;
		
	}


	return 0;
}
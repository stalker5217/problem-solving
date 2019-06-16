#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;

	getline(cin, str);

	for (int i = 0; i < str.size(); i++)
		str[i] = toupper(str[i]);

	cout << str;
}
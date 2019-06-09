#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	int sum = 0;

	getline(cin, str);

	for (int i = 0; i < str.size(); i++) {
		int n = str[i] - '0';
		sum += n;
	}

	cout << sum << endl;
}
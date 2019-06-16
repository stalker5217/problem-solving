#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	
	while (true) {
		string str;
		getline(cin, str);
		if (str.empty())
			break;

		cout << str << endl;
	}

	return 0;
}
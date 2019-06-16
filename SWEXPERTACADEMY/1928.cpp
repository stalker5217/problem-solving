#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int getValue(char c) {
	if (c >= 'A' && c <= 'Z')
		return c - 65;

	else if (c >= 'A' && c <= 'z') {
		return c - 71;
	}

	else if (c >= '0' && c <= '9')
		return c + 4;

	else if (c == '+')
		return 62;

	else if (c == '/')
		return 63;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	cin.get();
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string str;
		cin >> str;

		cout << "#" << test_case << " ";

		for (int i = 0; i < str.length(); i = i + 4) {
			int a = getValue(str[i]);
			int b = getValue(str[i + 1]);
			int c = getValue(str[i + 2]);
			int d = getValue(str[i + 3]);

			a = a << 18;
			b = b << 12;
			c = c << 6;
			//d

			int fourBit = 0;

			fourBit |= a;
			fourBit |= b;
			fourBit |= c;
			fourBit |= d;

			int temp;

			temp = fourBit;

			temp <<= 8;
			temp >>= 24;

			cout << (char)temp;

			temp = fourBit;

			temp <<= 16;
			temp >>= 24;

			cout << (char)temp;

			temp = fourBit;

			temp <<= 24;
			temp >>= 24;

			cout << (char)temp;
		}

		cout << endl;
	}
	return 0;
}
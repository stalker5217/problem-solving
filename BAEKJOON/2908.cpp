#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;


int main(int argc, char** argv)
{
	int first = 0, second = 0;
	string str;
	int n = 1;

	cin >> str;
	for (int i = 0; i < str.size() ; i++) {
		first += (str.at(i) - '0') * n;
		n *= 10;
	}

	n = 1;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		second += (str.at(i) - '0') * n;
		n *= 10;
	}

	if (first > second)
		cout << first << endl;
	else
		cout << second << endl;

	return 0;
}
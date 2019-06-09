#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;


int main(int argc, char** argv)
{
	int cnt = 0;
	while (true) {
		string str;
		cin >> str;
		if (str.empty() == true)
			break;
		else
			cnt++;
	}

	cout << cnt;

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	getchar();
	for (test_case = 1; test_case <= T; ++test_case)
	{
		char *str;
		str = (char*)malloc(sizeof(char) * 100);
		scanf("%s", str);

		int lastInt = str[strlen(str) - 1];
		lastInt -= '0';

		string result = (lastInt % 2 == 0) ? "Even" : "Odd";
		cout << "#" << test_case << " " << result << endl;
	}
	return 0;
}
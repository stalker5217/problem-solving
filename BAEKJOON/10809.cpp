#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;


int main(int argc, char** argv)
{
	string str;
	int alpha[26];

	cin >> str;

	for (int i = 0; i < 26; i++)
		alpha[i] = -1;

	for(int i = 0 ; i < str.length() ; i++)
		if (alpha[str[i] - 'a'] == -1) {
			alpha[str[i] - 'a'] = i;
		}

	for (int i = 0; i < 26; i++)
		cout << alpha[i] << " ";

	return 0;
}
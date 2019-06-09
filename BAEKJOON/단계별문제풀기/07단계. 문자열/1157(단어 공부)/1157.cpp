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
		alpha[i] = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z')
			alpha[str[i] - 'a']++;
		else
			alpha[str[i] - 'A']++;
	}
		
	bool same = false;
	int maxIndex = -1;
	int max = -1;

	for (int i = 0; i < 26; i++) {
		if (alpha[i] > max) {
			max = alpha[i];
			maxIndex = i;
			same = false;
		}

		else if (alpha[i] == max) {
			same = true;
		}
	}
	
	char answer = 'A' + maxIndex;
	if (same == true)
		cout << "?";
	else
		cout << answer;
	
	
	
	return 0;
}
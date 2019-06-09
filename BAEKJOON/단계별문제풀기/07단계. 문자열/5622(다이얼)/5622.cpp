#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;


int main(int argc, char** argv)
{
	string str;
	cin >> str;

	int total = 0;
	for (int i = 0; i < str.length(); i++) {
		int alp = str[i] - 'A';
		switch (alp) {
		case 0:
		case 1:
		case 2:
			total += 3;
			break;
		case 3:
		case 4:
		case 5:
			total += 4;
			break;
		case 6:
		case 7:
		case 8:
			total += 5;
			break;
		case 9:
		case 10:
		case 11:
			total += 6;
			break;
		case 12:
		case 13:
		case 14:
			total += 7;
			break;
		case 15:
		case 16:
		case 17:
		case 18:
			total += 8;
			break;
		case 19:
		case 20:
		case 21:
			total += 9;
			break;
		case 22:
		case 23:
		case 24:
		case 25:
			total += 10;
			break;
		}
	}

	cout << total;


	return 0;
}
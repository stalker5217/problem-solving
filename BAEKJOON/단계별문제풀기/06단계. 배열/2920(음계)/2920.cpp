#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;


int main(int argc, char** argv)
{
	bool asec = true;
	bool desc = true;
	
	int arr[8];
	for (int i = 0; i < 8; i++)
		cin >> arr[i];

	for (int i = 0; i < 8; i++) {
		if (arr[i] != i + 1) {
			asec = false;
		}
	}

	for (int i = 0; i < 8; i++) {
		if (arr[i] != 8 - i) {
			desc = false;
		}
	}

	if (asec == true)
		cout << "ascending" << endl;
	else if (desc == true)
		cout << "descending" << endl;
	else
		cout << "mixed" << endl;


	return 0;
}
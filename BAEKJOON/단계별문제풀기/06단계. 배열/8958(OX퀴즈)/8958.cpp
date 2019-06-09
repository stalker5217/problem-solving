#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	cin >> test_case;
	getchar();

	for (int t = 0; t < test_case; t++) {
		string str;
		
		getline(cin, str);

		int prev = 0;
		int score;
		int sum = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'O') {
				score = prev + 1;
				prev = score;
				sum += score;
			}
			else {
				prev = 0;
			}
		}

		//getchar();
		cout << sum << endl;
	}



	return 0;
}
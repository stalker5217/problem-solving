#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;



int main(int argc, char** argv)
{
	//freopen("input.txt", "r", stdin);
	int test_case;
	cin >> test_case;

	for (int t = 1; t <= test_case; t++) {
		unsigned long long num;
		cin >> num;

		unsigned long long x = 1;

		cout << "#" << t << " ";
		while (true) {
			if (x*x*x == num) {
				cout << x << "\n";
				break;
			}
			else if (x*x*x > num) {
				cout << "-1\n";
				break;
			}
			else {
				x++;
			}
		}



	}


	return 0;
}
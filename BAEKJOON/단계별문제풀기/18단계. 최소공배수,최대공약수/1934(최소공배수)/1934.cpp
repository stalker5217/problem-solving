#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	
	int test_case;
	cin >> test_case;

	for (int t = 0; t < test_case; t++) {
		int sa, sb;
		cin >> sa >> sb;

		int a = sa;
		int b = sb;
		while (true) {
			if (a > b) {
				b += sb;
			}
			else if (a < b) {
				a += sa;
			}
			else {
				cout << a << endl;
				break;
			}
		}
	
	}

	return 0;
}
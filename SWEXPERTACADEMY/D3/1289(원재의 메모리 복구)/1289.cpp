#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <stack>

using namespace std;


int main(int argc, char** argv)
{
	//freopen("input.txt", "r", stdin);
	int test_case;
	cin >> test_case;

	for (int t = 1; t <= test_case; t++) {
		string org;
		cin >> org;

		char cur = '0';
		int cnt = 0;
		for (int i = 0; i < org.length(); i++) {
			if (org[i] == cur) {
				continue;
			}
			else {
				cnt++;
				if (cur == '0')
					cur = '1';
				else
					cur = '0';
			}
		}
		cout << "#" << t << " " << cnt << endl;
	}

	
	return 0;
}
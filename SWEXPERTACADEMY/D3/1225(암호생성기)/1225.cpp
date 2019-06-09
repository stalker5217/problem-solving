#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <stack>
#include <deque>

using namespace std;

int main(){
	
	freopen("input.txt", "r", stdin);

	while (true) {
		if (cin.eof())
			break;

		int test_case;
		cin >> test_case;

		deque<int> password;

		for (int i = 0; i < 8; i++) {
			int temp;
			cin >> temp;

			password.push_back(temp);
		}

		int cnt = 1;
		while (true) {
			int temp = password.front();
			password.pop_front();
			temp -= cnt;
			if (temp < 0)
				temp = 0;

			password.push_back(temp);
			if (temp == 0) {
				cout << "#" << test_case << " ";
				for (int i = 0; i < password.size(); i++) {
					cout << password[i] << " ";
				}
				cout << "\n";
				break;
			}
			cnt++;
			if (cnt > 5)
				cnt = 1;
		}
	}

	return 0;
}
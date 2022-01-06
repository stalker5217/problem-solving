#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s; cin >> s;

	int remain = 0;
	for(int i = 0 ; i < s.size() ; i++) {
		int digit = s[i] - '0';
		remain = ((remain * 10) % 20'000'303 + digit) % 20'000'303;
	}

	cout << remain;

	return 0;
}
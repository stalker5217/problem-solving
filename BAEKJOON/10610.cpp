#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	string s; cin >> s;

	int sum = 0;
	bool existZero = false;
	for(int i = 0 ; i < s.size() ; i++) {
		int cur = s[i] - '0';
		if(cur == 0) existZero = true;
		
		sum += cur;
	}

	if(!existZero || sum % 3 > 0) cout << -1;
	else {
		sort(s.begin(), s.end(), [](char a, char b) {
			return a > b;
		});

		cout << s;
	}
	
	return 0;
}
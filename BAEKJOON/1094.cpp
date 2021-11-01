#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	string s; cin >> s;
	int zeroArea = 0, oneArea = 0;

	char prev = '2';
	for(int i = 0 ; i < s.size() ; i++) {
		if(prev != s[i]) {
			if(s[i] == '0') zeroArea++;
			else oneArea++;

			prev=s[i];
		}
	}

	int answer = (zeroArea < oneArea) ? zeroArea : oneArea;
	cout << answer;

    return 0;
}
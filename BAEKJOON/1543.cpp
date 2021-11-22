#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string haystack; getline(cin, haystack);
	string needle; getline(cin, needle);

	int cnt = 0, i = 0;
	while(i + needle.size() <= haystack.size()) {
		bool find = true;
		for(int j = 0 ; j < needle.size() ; j++) {
			if(haystack[i + j] != needle[j]) {
				find = false;
				break;
			}
		}

		if(find) {
			cnt++;
			i += needle.size();
		}
		else i++;
	}

	cout << cnt;
}
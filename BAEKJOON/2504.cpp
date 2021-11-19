#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;

	bool isValid = true;
	int answer = 0;
	int tmp = 1;
	stack<char> st;
	for(int i = 0 ; i < s.size() ; i++) {
		if(s[i] == '(' || s[i] == '[') {
			st.push(s[i]);
			tmp *= s[i] == '(' ? 2 : 3;
		}
		else if(s[i] == ')' || s[i] == ']') {
			if(st.empty()) {
				isValid = false;
				break;
			}

			if(s[i] == ')' && s[i-1] == '(') {
				answer += tmp;
				tmp /= 2;
			}
			else if(s[i] == ')' && st.top() == '(') {
				tmp /= 2;
			}
			else if(s[i] == ']' && s[i-1] == '[') {
				answer += tmp;
				tmp /= 3;
			}
			else if(s[i] == ']' && st.top() == '[') {
				tmp /= 3;
			}
			else {
				isValid = false;
				break;
			}

			st.pop();
		}
	}

	if(!st.empty()) isValid = false;

	if(!isValid) cout << 0;
	else cout << answer;

	return 0;
}
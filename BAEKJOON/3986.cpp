#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	int answer = 0;
	while(n--) {
		string s; cin >> s;
		stack<char> st;

		for(int i = 0 ; i < s.size() ; i++) {
			if(!st.empty() && st.top() == s[i]) st.pop();
			else st.push(s[i]);
		}

		if(st.empty()) answer++;
	}

	cout << answer;

	return 0;
}
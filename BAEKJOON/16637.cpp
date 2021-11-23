#include <iostream>
#include <string>
#include <functional>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	string exp; cin >> exp;

	function<int (int, int, char)> cal = [&](int a, int b, char op) {
		switch(op) {
			case '+' : return a + b;
			case '-' : return a - b;
			case '*' : return a * b;
		}

		return 0;
	};

	int answer = INT_MIN;
	function<void (int, int)> dfs = [&](int pos, int result) {
		if(pos > n) {
			answer = max(answer, result);
			return;
		}

		char op = pos == 0 ? '+' : exp[pos-1];
		if(pos + 2 < n) dfs(pos + 4, cal(result, cal(exp[pos] - '0', exp[pos + 2] - '0',  exp[pos + 1]), op));
		dfs(pos + 2, cal(result, exp[pos] - '0', op));
	};

	dfs(0, 0);

	cout << answer;

	return 0;
}
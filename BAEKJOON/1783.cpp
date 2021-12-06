#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int answer = 1;
	if(n == 2) answer = min((m + 1) / 2, 4);
	else if(n > 2) {
		if(m < 4) answer = m;
		else if(m < 6) answer = 4;
		else answer = m - 2;
	}

	cout << answer;

	return 0;
}
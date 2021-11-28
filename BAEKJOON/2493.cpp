#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	stack<pair<int, int> > towerStack;
	towerStack.push({123456789, 0});
	for(int i = 1 ; i <= n ; i++) {
		int height; cin >> height;

		while(towerStack.top().first < height) towerStack.pop();
		cout << towerStack.top().second << " ";

		towerStack.push({height, i});
	}

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testCase;
	cin >> testCase;
	while(testCase--) {
		int n; cin >> n;
		vector<int> to(n + 1, 0);
		for(int i = 1 ; i <= n ; i++) {
			cin >> to[i];	
		}

		vector<bool> visit(n + 1, false);
		int cycleCnt = 0;
		for(int i = 1 ; i <= n ; i++) {
			if(!visit[i]) {
				visit[i] = true;
				int next = to[i];
				while(!visit[next]) {
					visit[next] = true;
					next = to[next];
				}

				cycleCnt++;	
			}
		}

		cout << cycleCnt << "\n";
	}

	return 0;
}
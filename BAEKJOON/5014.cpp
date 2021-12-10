#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int height;
	int start;
	int target;
	int up;
	int down;

	cin >> height >> start >> target >> up >> down;
	vector<bool> visit(height + 1, false);
	bool findTarget = false;
	int tryCnt = 0;
	
	queue<int> q;
	q.push(start);
	visit[start] = true;
	while(!q.empty()) {
		int size = q.size();
		for(int i = 0 ; i < size ; i++) {
			int cur = q.front();
			q.pop();

			if(cur == target) {
				findTarget = true;
				break;
			}

			if(cur + up <= height && !visit[cur + up]) {
				visit[cur + up] = true;
				q.push(cur + up);
			}

			if(cur - down >= 1 && !visit[cur - down]) {
				visit[cur - down] = true;
				q.push(cur - down);
			}
		}
		
		if(findTarget) break;
		else tryCnt++;
	}

	if(findTarget) cout << tryCnt;
	else cout << "use the stairs";

	return 0;
}
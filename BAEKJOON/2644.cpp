#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin >> n;
	int x, y; cin >> x >> y;

	vector<vector<bool> > visit(n + 1, vector<bool>(n + 1, false));
	vector<vector<int> > adj(n + 1, vector<int>(0));
	int m; cin >> m;
	for(int i = 0 ; i < m ; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int relation = 0;

	queue<int> q;
	q.push(x);
	while(!q.empty()) {
		int qSize = q.size();
		relation++;

		for(int i = 0 ; i < qSize ; i++) {
			int cur = q.front();
			q.pop();

			for(int next : adj[cur]) {
				if(next == y) {
					cout << relation;

					return 0;
				}
				
				if(!visit[cur][next]) {
					visit[cur][next] = true;
					q.push(next);
				}
			}
		}
	}

	cout << -1;

	return 0;
}
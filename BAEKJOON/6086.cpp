#define INF 99999999
#define MAX_V 58

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<vector<int> > adjacent(MAX_V, vector<int>());
	vector<vector<int> > capacity(MAX_V, vector<int>(MAX_V, 0));
	vector<vector<int> > flow(MAX_V, vector<int>(MAX_V, 0));

	int n; cin >> n;
	string s; 
	getline(cin, s); // 개행 처리
	for(int i = 0 ; i < n ; i++) {
		getline(cin, s);
		int u = s[0] - 'A';
		int v = s[2] - 'A';
		int c = stoi(s.substr(4));

		adjacent[u].push_back(v);
		adjacent[v].push_back(u);

		capacity[u][v] += c;
		capacity[v][u] += c;
	}

	auto networkFlow = [&](int source, int sink) {
		int totalFlow = 0;

		while(true) {
			vector<int> parent(MAX_V, -1);
			queue<int> q;

			parent[source] = source;
			q.push(source);
			while(!q.empty() && parent[sink] == -1) {
				int here = q.front();
				q.pop();

				for(int there : adjacent[here]) {
					if(capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
						q.push(there);
						parent[there] = here;
					}
				}
			}

			if(parent[sink] == -1) break;

			int amount = INF;
			for(int p = sink ; p != source ; p = parent[p]) {
				amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
			}

			for(int p = sink ; p != source ; p = parent[p]) {
				flow[parent[p]][p] += amount;
				flow[p][parent[p]] -= amount;
			}

			totalFlow += amount;
		}

		return totalFlow;
	};

	cout << networkFlow('A' - 'A', 'Z' - 'A');

	return 0;
}
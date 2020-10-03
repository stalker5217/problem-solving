#define DEBUG 0
#define LOG(string) cout << string

#define INF 987654321

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int vertexCnt, pathCnt;
vector<pair<int, int> > adj[1001];
vector<int> trace;

vector<int> dijkstra(int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> vertexCnt >> pathCnt;

	for(int i = 0 ; i < pathCnt ; i++){
		int startV, destV, weight;
		cin >> startV >> destV >> weight;

		adj[startV].push_back({destV, weight});
	}

	int startV, destV;
	cin >> startV >> destV;
	vector<int> dist = dijkstra(startV);

	cout << dist[destV] << "\n";

	int cur = destV;
	vector<int> path;
	while(cur){
		path.push_back(cur);
		cur = trace[cur];
	}

	cout << path.size() << "\n";
	for(int i = path.size() - 1 ; i >= 0 ; i--) cout << path[i] << " ";
    
    return 0;
}

vector<int> dijkstra(int startV){
	vector<int> dist(vertexCnt + 1, INF);
	vector<int> parent(vertexCnt + 1, 0);
	
	dist[startV] = 0;

	priority_queue<pair<int, int> > pq;
	pq.push({0, startV});

	while(!pq.empty()){
		int cost = -pq.top().first;
		int curPos = pq.top().second;

		pq.pop();

		if(cost > dist[curPos]) continue;

		for(int i = 0 ; i < adj[curPos].size() ; i++){
			int to = adj[curPos][i].first;
			int viaCost = cost + adj[curPos][i].second;

			if(viaCost < dist[to]){
				dist[to] = viaCost;
				parent[to] = curPos;
				pq.push({-dist[to], to});
			}
		}
	}

	trace = parent;
	return dist;
}
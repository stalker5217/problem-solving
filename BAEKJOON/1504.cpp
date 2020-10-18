#define DEBUG 0
#define LOG(string) cout << string
#define INF 500000000

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int vertexCnt, pathCnt;
int viaPoint1, viaPoint2;

vector<pair<int, int> > adj[801];

vector<int> dijkstra(int startV);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> vertexCnt >> pathCnt;
	for(int i = 0 ; i < pathCnt ; i++){
		int startV, destV, weight;
		cin >> startV >> destV >> weight;

		adj[startV].push_back({destV, weight});
		adj[destV].push_back({startV, weight});
	}

	cin >> viaPoint1 >> viaPoint2;

	vector<int> fromStart = dijkstra(1);
	vector<int> fromPoint1 = dijkstra(viaPoint1);
	vector<int> fromPoint2 = dijkstra(viaPoint2);
	
	int dist1 = fromStart[viaPoint1] + fromPoint1[viaPoint2] + fromPoint2[vertexCnt];
	int dist2 = fromStart[viaPoint2] + fromPoint2[viaPoint1] + fromPoint1[vertexCnt];
	int answer = min(dist1, dist2);

	if(answer >= INF) cout << -1;
	else cout << answer;

    return 0;
}

vector<int> dijkstra(int startV){
	vector<int> dist(vertexCnt + 1, INF);
	dist[startV] = 0;

	priority_queue<pair<int, int> > pq;

	pq.push(make_pair(0, startV));

	while(!pq.empty()){
		int cost = -pq.top().first; // 기본 pq는 가장 큰 값이 우선 순위가 제일 높으므로 부호로 음수로 삽입을 하여 절대값이 작은 것부터 뽑음 
		int curPos = pq.top().second;
		pq.pop();

		// 만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 무시한다.
		if(dist[curPos] < cost) continue;

		for(int i = 0 ; i < adj[curPos].size() ; i++){
			int to = adj[curPos][i].first;
			int viaCost = cost + adj[curPos][i].second;

			// 더 짧은 경로를 발견하면 dist를 갱신하고 큐에 삽입한다.
			if(viaCost < dist[to]){
				dist[to] = viaCost;
				pq.push(make_pair(-dist[to], to)); // pq 우선순위 때문에 음수 값 삽입
			}
		}
	}

	return dist;
}
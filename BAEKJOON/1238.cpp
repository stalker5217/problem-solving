#define DEBUG 0
#define LOG(string) cout << string
#define INF 987654321

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int studentNum, pathCnt, targetSpot;

vector<int> dijkstra(int, vector<pair<int, int> > *);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> studentNum >> pathCnt >> targetSpot;

	vector<pair<int, int> > adjFromTarget[1001];
	vector<pair<int, int> > adjToTarget[1001];
	for(int i = 0 ; i < pathCnt ; i++){
		int startV, destV, weight;
		cin >> startV >> destV >> weight;

		adjFromTarget[startV].push_back(make_pair(destV, weight));
		adjToTarget[destV].push_back(make_pair(startV, weight));
	}

	vector<int> distFromTarget = dijkstra(targetSpot, adjFromTarget);
	vector<int> distToTarget = dijkstra(targetSpot, adjToTarget);

	int maxVal = -1;
	for(int i = 1 ; i <= studentNum ; i ++){
		int roundCost = distFromTarget[i] + distToTarget[i];
		maxVal = maxVal > roundCost ? maxVal : roundCost;
	}

	cout << maxVal;

    return 0;
}

vector<int> dijkstra(int startV, vector<pair<int, int> > adj[]){
	vector<int> dist(studentNum + 1, INF);
	dist[startV] = 0;

	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, startV));

	while(!pq.empty()){
		int cost = -pq.top().first;
		int curPos = pq.top().second;
		pq.pop();

		if(dist[curPos] < cost) continue;

		for(int i = 0 ; i < adj[curPos].size() ; i++){
			int to = adj[curPos][i].first;
			int viaCost = cost + adj[curPos][i].second;

			if(viaCost < dist[to]){
				dist[to] = viaCost;
				pq.push(make_pair(-dist[to], to));
			}
		}
	}

	return dist;
}
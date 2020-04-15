#define DEBUG 0
#define LOG(string) cout << string

#define INF 99999999

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dist[20001];
vector<pair<int, int> > distInfo[20001];

void dijkstra(int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int vertexCnt;
	int edgeCnt;
	cin >> vertexCnt >> edgeCnt;

	int startPos;
	cin >> startPos;

	for(int i = 1 ; i <= vertexCnt ; i++){
		dist[i] = INF;
	}

	for(int i = 0 ; i < edgeCnt ; i++){
		int from, to, weight;
		cin >> from >> to >> weight;

		distInfo[from].push_back(make_pair(to, weight));
	}
    
	dijkstra(startPos);

	for(int i = 1 ; i <= vertexCnt ; i++){
		if(dist[i] == INF) cout << "INF" << "\n";
		else cout << dist[i] << "\n";
	}
    
    return 0;
}

void dijkstra(int startPos){
	dist[startPos] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, startPos));
	
	while(!pq.empty()){
		int cost = -pq.top().first;
		int curPos = pq.top().second;
		pq.pop();

		if(dist[curPos] < cost) continue;

		for(int i = 0 ; i < distInfo[curPos].size() ; i++){
			int to = distInfo[curPos][i].first;
			int viaCost = cost + distInfo[curPos][i].second;

			if(viaCost < dist[to]){
				dist[to] = viaCost;
				pq.push(make_pair(-viaCost, to));
			}
		}
	}
}

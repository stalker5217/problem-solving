#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>

using namespace std;

const int MAX_V = 10000;
const int INF = 987654321;

// 정점의 개수
int vertexCnt;

// 인접 리스트
vector<pair<int, int> > adj[MAX_V];

int prim(vector<pair<int, int> > & selected);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int edgeCnt;
	cin >> vertexCnt >> edgeCnt;
	
	for(int i = 0 ; i < edgeCnt ; i++){
		int start, dest, weight;
		cin >> start >> dest >> weight;
		adj[start-1].push_back({dest-1, weight});
		adj[dest-1].push_back({start-1, weight});
	}

	vector<pair<int, int> > selected;
	cout << prim(selected);
    
    return 0;
}

int prim(vector<pair<int, int> > & selected){
    selected.clear();

    // 정점이 Spanning Tree에 포함되어 있는지 여부
    vector<bool> added(vertexCnt, false);

    // 트리에 인접한 간선 중 해당 정점에 닿는 가중치가 가장 작은 간선의 정보를 저장
    vector<int> minWeight(vertexCnt, INF);
    vector<int> parent(vertexCnt, -1);

    int ret = 0;

    minWeight[0] = 0;
    parent[0] = 0;

    for(int iter = 0 ; iter < vertexCnt ; iter++){
        // 다음 추가할 정점 u를 찾는다.
        int u = -1;
        for(int v = 0 ; v < vertexCnt ; v++){
            if(!added[v] && (u == -1 || minWeight[u] > minWeight[v])) u = v;
        }

        if(parent[u] != u) selected.push_back({parent[u], u});

        ret += minWeight[u];
        added[u] = true;

        // u에 인접한 간선을 검사한다.
        for(int i = 0 ; i < adj[u].size() ; i++){
            int v = adj[u][i].first;
            int weight = adj[u][i].second;

            if(!added[v] && minWeight[v] > weight){
                parent[v] = u;
                minWeight[v] = weight;
            }
        }
    }

    return ret;
}
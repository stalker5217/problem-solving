#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_V = 100000;
const int INF = 987654321;

// 정점의 개수
int vertexCnt;

// 인접 리스트
vector<pair<int, int> > adj[MAX_V];

struct DisjointSet{
	vector<int> parent;
	vector<int> rank;

	DisjointSet(int n)
	: parent(n), rank(n, 1)
	{
		for(int i = 0 ; i < n ; i++){
			parent[i] = i;
		}
	}

	// 경로 압축 최적화
	int find(int u) {
		if(u == parent[u]) return u;
		else return parent[u] = find(parent[u]);
	}

	// u, v가 속해 있는 각각의 트리를 합친다
	void merge(int u, int v){
	u = find(u);
	v = find(v);

	if(u == v) return;
	if(rank[u] > rank[v]) swap(u, v);
	parent[u] = v;
	if(rank[u] == rank[v]) ++rank[v];
	}
};

int kruskal(vector<pair<int, int> > & selected);

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
	cout << kruskal(selected);
    
    return 0;
}

/*
 *  @param selected 선택된 엣지 목록 저장
 *  @return ret MST를 구성하는 가중치의 합
 */
int kruskal(vector<pair<int, int> > & selected){
	int ret = 0;
	selected.clear();

	// (weight, (u, v))
	// 가중치 기준으로 검사하기 위해 데이터 손질
	vector<pair<int, pair<int, int> > > edges;
	for(int u = 0 ; u < vertexCnt ; u++){
		for(int i = 0 ; i < adj[u].size() ; i++){
		int v = adj[u][i].first;
		int cost = adj[u][i].second;
		edges.push_back({cost, {u, v}});
		}
	}

  	sort(edges.begin(), edges.end());

  	// 처음에는 모든 Vertex가 분리
  	DisjointSet sets(vertexCnt);

	int maxCost = -1;
	for(int i = 0 ; i < edges.size() ; i++){
		int cost = edges[i].first;
		int u = edges[i].second.first;
		int v = edges[i].second.second;

		// 사이클을 생성하면 무시
		if(sets.find(u) == sets.find(v)) continue;

		sets.merge(u, v);
		selected.push_back(make_pair(u, v));
		ret += cost;
		maxCost = max(maxCost, cost);
	}

 	return ret - maxCost;
}
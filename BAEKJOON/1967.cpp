#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int nodeCnt;
vector<pair<int, int> > tree[10001];
bool visit[10001];
int maxDist, maxNum;

void dfs(int, int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> nodeCnt;
	for(int i = 0 ; i < nodeCnt - 1 ; i++){
		int parent, child, weight;
		cin >> parent >> child >> weight;
		tree[parent].push_back({child, weight});
		tree[child].push_back({parent, weight});
	}

	maxDist = 0;
	memset(visit, false, sizeof(bool) * 10001);
	dfs(1, 0);

	maxDist = 0;
	memset(visit, false, sizeof(bool) * 10001);
	dfs(maxNum, 0);

	cout << maxDist;

    return 0;
}

void dfs(int nodeNum, int cost){
	if(cost > maxDist){
		maxDist = cost;
		maxNum = nodeNum;
	}

	visit[nodeNum] = true;

	for(int i = 0 ; i < tree[nodeNum].size() ; i++){
		if(!visit[tree[nodeNum][i].first]){
			dfs(tree[nodeNum][i].first, cost + tree[nodeNum][i].second);
		}
	}
}
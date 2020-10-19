#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int nodeCnt;
vector<pair<int, int> > tree[100001];
bool visit[100001];
int maxDist, maxNum;

void dfs(int, int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> nodeCnt;
	for(int i = 0 ; i < nodeCnt ; i++){
		int nodeNum;
		cin >> nodeNum;
		for(;;){
			int targetNum, weight;
			cin >> targetNum;
			
			if(targetNum == -1) break;	
			
			cin >> weight;

			tree[nodeNum].push_back({targetNum, weight});
			tree[targetNum].push_back({nodeNum, weight});
		}
	}

	maxDist = 0;
	memset(visit, false, sizeof(bool) * 100001);
	dfs(1, 0);

	maxDist = 0;
	memset(visit, false, sizeof(bool) * 100001);
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
#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v, e;
vector<vector<int> > adj;
vector<int> discovered;
vector<bool> isCutVertex;
int counter = 0;

int findCutVertex(int, bool);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> v >> e;
	adj.assign(v+1, vector<int>(0));
	discovered.assign(v+1, -1);
	isCutVertex.assign(v+1, false);
	for(int i = 0 ; i < e ; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i = 1 ; i <= v ; i++){
		if(discovered[i] == -1){
			findCutVertex(i, true);
		}
	}

	int answer = 0;
	vector<int> cutVertexList;
	for(int i = 1 ; i <= v ; i++){
		if(isCutVertex[i]){
			answer++;
			cutVertexList.push_back(i);
		}
	}

	cout << answer << "\n";
	for(int cutVertex : cutVertexList){
		cout << cutVertex << " ";
	}

    return 0;
}

int findCutVertex(int here, bool isRoot){
	discovered[here] = counter++;
	int ret = discovered[here];
	int children = 0;

	for(int next : adj[here]){
		if(discovered[next] == -1){
			++children;

			int subTree = findCutVertex(next, false);

			if(!isRoot && subTree >= discovered[here]) isCutVertex[here] = true;
			ret = min(ret, subTree);
		}
		else{
			ret = min(ret, discovered[next]);
		}
	}

	if(isRoot) isCutVertex[here] = (children >= 2);
	return ret;
}
#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v, e;
vector<vector<int> > adj;
vector<int> discovered;
vector<pair<int, int> > cutEdges;
int counter = 0;

int findCutEdge(int, int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> v >> e;
	adj.assign(v+1, vector<int>(0));
	discovered.assign(v+1, -1);
	for(int i = 0 ; i < e ; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i = 1 ; i <= v ; i++){
		if(discovered[i] == -1){
			findCutEdge(i, -1);
		}
	}

	sort(cutEdges.begin(), cutEdges.end());

	cout << cutEdges.size() << "\n";
	for(pair<int, int> edge : cutEdges) cout << edge.first << " " << edge.second << "\n";

    return 0;
}

int findCutEdge(int here, int parent){
	discovered[here] = counter++;
	int ret = discovered[here];

	for(int next : adj[here]){
		if(next == parent) continue;
		else if(discovered[next] >= 0) ret = min(ret, discovered[next]);
		else{
			int prev = findCutEdge(next, here);
			if(prev > discovered[here]) cutEdges.push_back({min(here, next), max(here, next)});

			ret = min(ret, prev);
		}
	}

	return ret;
}
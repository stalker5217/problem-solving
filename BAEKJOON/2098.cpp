#define INF 987654321
#define MAX 16

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int dist[MAX][MAX];
int cache[MAX][1 << MAX];

int shortestPath(int here, int visited){
	if(visited == (1 << n) - 1){
		return dist[here][0] == 0 ? INF : dist[here][0];
	}

	int& ret = cache[here][visited];
	if(ret >= 0) return ret;
	ret = INF;
	for(int next = 0 ; next < n ; next++){
		if(visited & (1 << next) || dist[here][next] == 0) continue;

		int cand = dist[here][next] + shortestPath(next, visited + (1 << next));
		ret = min(ret, cand);
	}

	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> dist[i][j];
		}
	}

	memset(cache, -1, sizeof(cache));
	cout << shortestPath(0, 1);

	return 0;
}
#define INF 987654321

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int dist[10][10];
bool visited[10];
vector<int> path;

int shortestPath(int distance){
	if(path.size() == n){
		if(dist[path.back()][path[0]] > 0) return distance + dist[path.back()][path[0]];
		else return INF;
	}

	int ret = INF;
	for(int next = 0 ; next < n ; next++){
		int here = path.back();
		if(visited[next] || dist[here][next] == 0) continue;

		path.push_back(next);
		visited[next] = true;

		int cand = shortestPath(distance + dist[here][next]);
		ret = min(ret, cand);

		path.pop_back();
		visited[next] = false;
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

	int answer = INF;
	for(int i = 0 ; i < n ; i++){
		path.clear();
		path.push_back(i);
		memset(visited, false, sizeof(visited));
		visited[i] = true;
		answer = min(answer, shortestPath(i));
	}
	
	cout << answer;

	return 0;
}
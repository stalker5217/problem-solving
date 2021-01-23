#define DEBUG 0
#define LOG(string) cout << string
#define INF 987654321

#include <iostream>
#include <algorithm>

using namespace std;

int vertexCnt, pathCnt;
int adj[101][101];

void floydWarshall();

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> vertexCnt >> pathCnt;

	// init
	for(int i = 1 ; i <= vertexCnt ; i++){
		for(int j = 1 ; j <= vertexCnt ; j++){
			if(i == j) adj[i][j] = 0;
			else adj[i][j] = INF;
		}
	}

	for(int i = 0 ; i < pathCnt ; i++){
		int startV, destV, weight;
		cin >> startV >> destV >> weight;
		adj[startV][destV] = min(weight, adj[startV][destV]);
	}

	floydWarshall();

	for(int i = 1 ; i <= vertexCnt ; i++){
		for(int j = 1 ; j <= vertexCnt ; j++){
			if(adj[i][j] == INF) adj[i][j] = 0;
		}
	}

	for(int i = 1 ; i <= vertexCnt ; i++){
		for(int j = 1 ; j <= vertexCnt ; j++){
			cout << adj[i][j] << " ";
		}
		cout << "\n";
	}

    return 0;
}

void floydWarshall(){
	for(int k = 1 ; k <= vertexCnt ; k++){
		for(int i = 1 ; i <= vertexCnt ; i++){
			for(int j = 1 ; j <= vertexCnt ; j++){
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
}
#define DEBUG 0
#define LOG(string) cout << string
#define INF 987654321

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int vertexCnt, searchRange, pathCnt;
int adj[101][101];

void floydWarshall();

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> vertexCnt >> searchRange >> pathCnt;
	vector<int> itemCnt(vertexCnt + 1, 0);
	for(int i = 1 ; i <= vertexCnt ; i++){
		cin >> itemCnt[i];
	}

	// initialization
	for(int i = 1 ; i <= vertexCnt ; i++){
		for(int j = 1 ; j <= vertexCnt ; j++){
			if(i == j) adj[i][j] = 0;
			else adj[i][j] = INF;
		}
	}

	for(int i = 0 ; i < pathCnt ; i++){
		int startV, destV, weight;
		cin >> startV >> destV >> weight;
		adj[startV][destV] = weight;
		adj[destV][startV] = weight;
	}

	floydWarshall();

	int maxItemSum = 0;
	for(int i = 1 ; i <= vertexCnt ; i++){
		int sum = 0;
		for(int j = 1; j <= vertexCnt ; j++){
			if(adj[i][j] <= searchRange){
				sum += itemCnt[j];
			}
		}
		maxItemSum = max(maxItemSum, sum);
	}

	cout << maxItemSum;
    
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
#define DEBUG 0
#define LOG(string) cout << string
#define INF 123456789

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int vertexCnt, pathCnt;
int qCnt;

int adj[401][401];

void floydWarshall();

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> vertexCnt >> pathCnt;

    for(int i = 1 ; i <= vertexCnt ; i++){
        for(int j = 1 ; j <= vertexCnt ; j++){
            if(i == j) adj[i][j] = 0;
            else adj[i][j] = INF;
        }
    }

    for(int i = 0 ; i < pathCnt ; i++){
        int startV, destV;
        cin >> startV >> destV;
        adj[startV][destV] = 1;
    }

    floydWarshall();

    cin >> qCnt;
    for(int i = 0 ; i < qCnt ; i++){
        int v1, v2;
        cin >> v1 >> v2;
        if(adj[v1][v2] < INF) cout << "-1\n";
        else if(adj[v2][v1] < INF) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}

void floydWarshall(){
    for(int k = 1 ; k <= vertexCnt ; k++){
        for(int i = 1 ; i <= vertexCnt ; i++){
            for(int j = 1 ; j <= vertexCnt ; j++){
                adj[i][j] = adj[i][j] < adj[i][k] + adj[k][j] ? adj[i][j] : adj[i][k] + adj[k][j];
            }
        }
    }
}
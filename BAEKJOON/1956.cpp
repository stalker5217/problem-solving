#define DEBUG 0
#define LOG(string) cout << string
#define INF 123456789

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int vertexCnt, pathCnt;
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
        int startV, destV, weight;
        cin >> startV >> destV >> weight;

        adj[startV][destV] = weight;
    }

    floydWarshall();

    int answer = INF;
    for(int i = 1 ; i <= vertexCnt ; i++){
        for(int j = i + 1 ; j <= vertexCnt ; j++){
            if(adj[i][j] != INF && adj[j][i] != INF){
                int cycleSum = adj[i][j] + adj[j][i];
                answer = answer < cycleSum ? answer : cycleSum;
            }
        }
    }

    if(answer < INF) cout << answer;
    else cout << -1;

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
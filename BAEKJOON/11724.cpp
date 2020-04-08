#include <iostream>
#include <vector>

#define WHITE 0
#define BLUE 1

using namespace std;

int map[128][128];

void divideMap(int, int, int);

int vertexCnt;
int connectCnt;

bool isConnected[1001][1001];
bool isVisited[1001];

void dfsSearch(int);

int main(){
    cin >> vertexCnt >> connectCnt;
    for(int i = 0 ; i < connectCnt ; i++){
        int a, b;
        cin >> a >> b;
        isConnected[a][b] = true;
        isConnected[b][a] = true;
    }

    int areaCnt = 0;
    for(int i = 1 ; i <= vertexCnt ; i++){
        if(!isVisited[i]){
            dfsSearch(i);
            areaCnt++;
        }
    }

    cout << areaCnt;

    return 0;
}

void dfsSearch(int vIdx){
    isVisited[vIdx] = true;
    for(int i = 1 ; i <= vertexCnt ; i++){
        if(isConnected[vIdx][i] && !isVisited[i]) dfsSearch(i);
    }
}
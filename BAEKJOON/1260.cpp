#include <iostream>
#include <queue>

#define WHITE 0
#define BLUE 1

using namespace std;

int map[128][128];

void divideMap(int, int, int);

int vertexCnt;
int connectCnt;

bool isConnected[1001][1001];
bool isVisitedD[1001];
bool isVisitedB[1001];

void dfsSearch(int);
queue<int> candidate;
void bfsSearch(int);

int main(){
    int startPos;
    cin >> vertexCnt >> connectCnt >> startPos;
    for(int i = 0 ; i < connectCnt ; i++){
        int a, b;
        cin >> a >> b;
        isConnected[a][b] = true;
        isConnected[b][a] = true;
    }

    dfsSearch(startPos); cout <<"\n";
    bfsSearch(startPos);

    return 0;
}

void dfsSearch(int pos){
    isVisitedD[pos] = true;
    cout << pos << " ";
    for(int i = 1 ; i <= vertexCnt ; i++){
        //cout << isConnected[pos][i] << " " << !isVisitedD[i] << endl;
        if(isConnected[pos][i] && !isVisitedD[i]) dfsSearch(i);
    }
}

void bfsSearch(int startPos){
    candidate.push(startPos);
    
    while(true){
        if(candidate.empty()){
            break;
        }

        int pos = candidate.front();
        candidate.pop();
        if(!isVisitedB[pos]){
            isVisitedB[pos] = true;
            cout << pos << " ";
            for(int i = 1 ; i <= vertexCnt ; i++){
                if(isConnected[pos][i] && !isVisitedB[i]) candidate.push(i);
            }
        }
    }
}
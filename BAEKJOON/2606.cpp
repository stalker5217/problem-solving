#include <iostream>

using namespace std;

int isConnect[101][101];
int infected[101];
int computerCnt;

void infectSimulation(int);

int main(){
    cin >> computerCnt;

    int connectListSize;
    cin >> connectListSize;

    for(int i = 0 ; i < connectListSize ; i++){
        int a, b;
        cin >> a >> b;

        isConnect[a][b] = 1;
        isConnect[b][a] = 1;
    }

    infectSimulation(1);
    int infectedCnt = 0;
    for(int i = 1 ; i <= computerCnt ; i++){
        if(infected[i] == 1) infectedCnt++;
    }
    cout << infectedCnt - 1;

    return 0;
}

void infectSimulation(int num){
    infected[num] = 1;
    for(int i = 1 ; i <= computerCnt ; i++){
        if(infected[i] == 0 && isConnect[num][i] == 1) infectSimulation(i);
    }
}
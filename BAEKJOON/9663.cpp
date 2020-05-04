#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cmath>

using namespace std;

int queenCol[15];

void dfs(int);
bool isPromising(int);

int n;
int promiseCnt;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    dfs(0);
    cout << promiseCnt;
    
    return 0;
}

void dfs(int row){
    if(row == n) {
        promiseCnt++;
        return;
    }

    for(int i = 0 ; i < n ; i++){
        queenCol[row] = i;
        if(isPromising(row)) dfs(row+1);
    }
}

bool isPromising(int row){
    for(int i = 0 ; i < row ; i++){
        if(queenCol[i] == queenCol[row]) return false;
        if(abs(queenCol[row] - queenCol[i]) == abs(row - i)) return false;
    }

    return true;
}
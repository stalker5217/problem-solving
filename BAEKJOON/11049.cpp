#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <cstring>
#include <limits>

using namespace std;

int n;
vector<pair<int, int> > matrixSize;
int dp[501][501];

int makeAnswer(int, int);

int min(int a, int b){
    return a > b ? b : a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    matrixSize.push_back({0, 0}); // dummy
    for(int i = 1 ; i <= n ; i++){
        int a, b;
        cin >> a >> b;
        matrixSize.push_back({a, b});
    }
    
    memset(dp, -1, sizeof(dp));
    makeAnswer(1, n);

    cout << makeAnswer(1, n);

    return 0;
}

int makeAnswer(int a, int b){
    if(a == b) return 0;
    if(dp[a][b] >= 0) return dp[a][b];

    int result = INT32_MAX;
    for(int i = a ; i < b ; i++){
        result = min(result, makeAnswer(a, i) + makeAnswer(i+1, b) + (matrixSize[a].first * matrixSize[b].second * matrixSize[i].second));
    }

    dp[a][b] = result;
    return dp[a][b];
}
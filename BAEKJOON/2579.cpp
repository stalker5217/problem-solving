#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void dfs(int height, int continueCnt);

int n;
int score[301];
int dp[301];
vector<int> stairs;
int answer;

int max(int a, int b){
	return a > b ? a : b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> score[i];
	}

	dp[0] = 0;
	dp[1] = score[1];
	dp[2] = score[1] + score[2];

	for(int i = 3 ; i <= n ; i++){
		dp[i] = max(dp[i-2] + score[i], dp[i-3] + score[i-1] + score[i]);
	}

	cout << dp[n];
    
    return 0;
}


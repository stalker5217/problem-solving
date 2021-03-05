#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, capacity;
int sum = 0;
int memory[100];
int bootTime[100];
int dp[100][10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n >> capacity;

	for(int i = 0 ; i < n ; i++) cin >> memory[i];
	for(int i = 0 ; i < n ; i++){
		cin >> bootTime[i];
		sum += bootTime[i];
	}

	memset(dp, 0 , sizeof(dp));
	dp[0][bootTime[0]] = memory[0];
	for(int i = 1 ; i < n ; i++){
		for(int j = 0 ; j <= sum ; j++){
			if(j - bootTime[i] >= 0){
				dp[i][j] = max(dp[i-1][j], dp[i-1][j - bootTime[i]] + memory[i]);
			}
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
		}
	}

	for(int j = 0 ; ; j++){
		if(dp[n-1][j] >= capacity){
			cout << j;
			break;
		}
	}

    return 0;
}
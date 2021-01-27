#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	int val[1000];
	for(int i = 0 ; i < n ; i++){
		cin >> val[i];
	}

	int dp[2][1000];
	
	for(int i = 0 ; i < n ; i++){
		dp[0][i] = 1;
		for(int j = 0 ; j < i ; j++){
			if(val[j] < val[i] && dp[0][j] >= dp[0][i]){
				dp[0][i] = dp[0][j] + 1;
			}
		}
	}

	for(int i = n-1 ; i >= 0 ; i--){
		dp[1][i] = 1;
		for(int j = n-1 ; j > i ; j--){
			if(val[j] < val[i] && dp[1][j] >= dp[1][i]){
				dp[1][i] = dp[1][j] + 1;
			}
		}
	}

	int answer = 0;
	for(int i = 0 ; i < n ; i++){
		answer = max(answer, dp[0][i] + dp[1][i]);
	}
	answer--;

	cout << answer;

    return 0;
}
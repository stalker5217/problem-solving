#include <iostream>
#include <vector>
#include <cstring>

#define EMPTY 0
#define WALL 1

#define H 0 // 가로
#define V 1 // 세로
#define D 2 // 대각

using namespace std;

const int MAX_N = 32;
int n;
int map[MAX_N][MAX_N];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> map[i][j];
		}
	}

	long long dp[3][MAX_N][MAX_N];
	memset(dp, 0, sizeof(dp));

	dp[0][0][1] = 1;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			// 가로
			if(j + 1 < n && map[i][j+1] == 0){
				dp[H][i][j + 1] += dp[H][i][j];
				dp[H][i][j + 1] += dp[D][i][j];
			}
			// 세로
			if(i + 1 < n && map[i+1][j] == 0){
				dp[V][i + 1][j] += dp[V][i][j];
				dp[V][i + 1][j] += dp[D][i][j];
			}
			// 대각선
			if(i + 1 < n && j + 1 < n && map[i + 1][j] == 0 && map[i][j + 1] == 0 && map[i + 1][j + 1] == 0){
				dp[D][i + 1][j + 1] += dp[H][i][j];
				dp[D][i + 1][j + 1] += dp[V][i][j];
				dp[D][i + 1][j + 1] += dp[D][i][j];
			}
		}
	}

	long long cnt = dp[H][n-1][n-1] + dp[V][n-1][n-1] + dp[D][n-1][n-1];
	cout << cnt;

	return 0;
}
#define DEBUG 0
#define LOG(string) cout << string
#define INF 987654321

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	int min_dp[3] = {0, 0, 0};
	int max_dp[3] = {0, 0, 0};
	for(int i = 0 ; i < n ; i++){
		int cur[3] = {0, 0, 0};
		int max_new_dp[3] = {0, 0, 0};
		int min_new_dp[3] = {0, 0, 0};
		cin >> cur[0] >> cur[1] >> cur[2];

		for(int j = 0 ; j < 3 ; j++){
			int maxVal = -1;
			if(j != 0) maxVal = max(maxVal, max_dp[j-1]);
			if(j != 2) maxVal = max(maxVal, max_dp[j+1]);
			maxVal = max(maxVal, max_dp[j]);
			
			max_new_dp[j] = maxVal + cur[j];

			int minVal = INF;
			if(j != 0) minVal = min(minVal, min_dp[j-1]);
			if(j != 2) minVal = min(minVal, min_dp[j+1]);
			minVal = min(minVal, min_dp[j]);

			min_new_dp[j] = minVal + cur[j];
		}

		max_dp[0] = max_new_dp[0]; 
		max_dp[1] = max_new_dp[1]; 
		max_dp[2] = max_new_dp[2]; 
		
		min_dp[0] = min_new_dp[0]; 
		min_dp[1] = min_new_dp[1]; 
		min_dp[2] = min_new_dp[2];
	}

	int maxResult = -1;
	int minResult = INF;
	for(int i = 0 ; i < 3 ; i++){
		maxResult = max(maxResult, max_dp[i]);
		minResult = min(minResult, min_dp[i]);
	}

	cout << maxResult << " " << minResult;

    return 0;
}
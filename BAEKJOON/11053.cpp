#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <algorithm>

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

	int dp[1000];
	for(int i = 0 ; i < n ; i++){
		dp[i] = 1;
		for(int j = 0 ; j < i ; j++){
			if(val[j] < val[i] && dp[j] >= dp[i]){
				dp[i] = dp[j] + 1;
			}
		}
	}

	int answer = 0;
	for(int i = 0 ; i < n ; i++){
		answer = max(answer, dp[i]);
	}

	cout << answer;

    return 0;
}
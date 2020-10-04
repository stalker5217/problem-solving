#define DEBUG 0
#define LOG(string) cout << string

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[101][100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int stuffCnt, knapsackVolume;
	cin >> stuffCnt >> knapsackVolume;

	vector<pair<int, int> > stuffList;
	stuffList.push_back({0, 0}); // dummy
	for(int i = 1 ; i <= stuffCnt ; i++){
		int weight, value;
		cin >> weight >> value;
		stuffList.push_back({weight, value});
	}

	for(int i = 1 ; i <= stuffCnt ; i++){
		for(int j = 1 ; j <= knapsackVolume ; j++){
			dp[i][j] = dp[i-1][j];
			if(stuffList[i].first <= j){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - stuffList[i].first] + stuffList[i].second);
			}
		}
	}

	cout << dp[stuffCnt][knapsackVolume];
    
    return 0;
}
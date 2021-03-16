#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 1001;
int dp[MAX][MAX];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;
	for(int i = 1 ; i <= a.length() ; i++){
		for(int j = 1 ; j <= b.length() ; j++){
			if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	cout << dp[a.length()][b.length()];

	return 0;
}
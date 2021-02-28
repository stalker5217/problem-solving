#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

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

	cout << dp[a.length()][b.length()] << "\n";

	vector<char> answer;
	int i = a.length();
    int j = b.length();
    while(i != 0 && j != 0){
        if(dp[i][j] == dp[i-1][j]) i--;
		else if(dp[i][j] == dp[i][j-1]) j--;
		else{
            answer.push_back(a[i-1]);
            i--;
            j--;
        }
    }
    
    for(int i = answer.size()-1 ; i>=0 ; i--){
        cout << answer[i];
    }
    
	return 0;
}
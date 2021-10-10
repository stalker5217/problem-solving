#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    cin >> str;
	int length = str.size();

	// add dummy
	str = " " + str;

	// Find Palindrom
	vector<vector<bool> > isPalindrom(length + 1, vector<bool>(length + 1));
    for(int i = 1 ; i <= length ; i++) isPalindrom[i][i] = true;
	for(int i = 1 ; i <= length - 1 ; i++) isPalindrom[i][i+1] = str[i] == str[i+1] ? true : false;
	for(int i = 2 ; i < length ; i++) {
		for(int j = 1 ; j + i <= length ; j++) {
			if(str[j] == str[j + i] && isPalindrom[j + 1][j + i - 1]) isPalindrom[j][j + i] = true;
		}
	} 

	// dp
	vector<int> dp(length + 1);
	dp[0] = 0;
	for(int i = 1 ; i <= length ; i++) {
		dp[i] = 1000000000;	
		for(int j = 1 ; j <= i ; j++) {
			if(isPalindrom[j][i]) {
				dp[i] = min(dp[i], dp[j - 1] + 1);
			}
		}
	}

	cout << dp[length];

    return 0;
}
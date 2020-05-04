#define DEBUG 0
#define LOG(string) cout << string
#define MAXVAL 1000
#define MODVAL 10007

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int dp[MAXVAL + 1];
    dp[1] = 1;
    dp[2] = 3;

    for(int i = 3 ; i <= n ; i++){
        dp[i] = (dp[i-2] * 2 + dp[i-1]) % MODVAL;
    }
    
    cout << dp[n];

    return 0;
}

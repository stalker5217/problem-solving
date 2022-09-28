#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));
        for(int i = 1 ; i <= min(target, k); i++) {
            dp[1][i] = 1;    
        }
        
        for(int a = 2 ; a <= n ; a++) {
            for(int b = 1 ; b <= min(a * k, target) ; b++) {
                for(int c = 1 ; c <= min(b, k) ; c++) {
					dp[a][b] += dp[a-1][b-c];
					dp[a][b] %= 1000000007;
                }
            }
        }
        
        return dp[n][target];
    }
};
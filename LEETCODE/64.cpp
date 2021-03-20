#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int> > dp(n, vector<int>(m, 0));
        
        for(int i = 0, sum = 0 ; i < m ; i++){
            sum += grid[0][i];
            dp[0][i] = sum;
        }
        
        for(int i = 0, sum = 0 ; i < n ; i++){
            sum += grid[i][0];
            dp[i][0] = sum;
        }

        
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j < m ; j++){
                int minVal = dp[i-1][j] < dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
                dp[i][j] = minVal + grid[i][j];
            }
        }
        
        return dp[n-1][m-1];
    }
};
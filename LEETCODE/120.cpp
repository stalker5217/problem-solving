#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int> > dp(triangle.size(), vector<int>(triangle[triangle.size()-1].size(), -100000));
        return helper(triangle, dp, 0, 0);
    }
    
    int helper(vector<vector<int>>& triangle, vector<vector<int>>& dp, int height, int pos) {
        if(height == triangle.size() - 1) return triangle[height][pos];
        else if(dp[height][pos] > -100000) return dp[height][pos];
        
        return dp[height][pos] = triangle[height][pos] + min(
            helper(triangle, dp, height + 1, pos),
            helper(triangle, dp, height + 1 ,pos + 1)
        );
    }
};
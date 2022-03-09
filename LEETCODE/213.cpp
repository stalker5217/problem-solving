#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        vector<int> dp1(nums.size(), 0);
        vector<int> dp2(nums.size(), 0);
        
        dp1[0] = nums[0]; dp1[1] = nums[0];
        dp2[0] = 0; dp2[1] = nums[1];
        
        for(int i = 2 ; i < nums.size() - 1 ; i++) {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
        }
        
        for(int i = 2; i < nums.size() ; i++) {
            dp2[i] = max(dp2[i - 1], dp2[i - 2]  + nums[i]);
        }
        
        return max(dp1[dp1.size() - 2], dp2[dp2.size() - 1]);
    }
};
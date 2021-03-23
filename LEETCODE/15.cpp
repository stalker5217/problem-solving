#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        if(nums.size() < 3) return ret;
        
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size() - 2 ; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            int start = i+1;
            int end = nums.size() - 1;
            
            while(start < end){
                int sum = nums[i] + nums[start] + nums[end];
            
                if(sum == 0){
                    ret.push_back({nums[i], nums[start], nums[end]});
                    while(start < nums.size() - 1 && nums[start] == nums[++start]);
                    while(end > 0 && nums[end] == nums[--end]);
                }
                else if(sum < 0) start++;
                else end--;
            }
        }
        
        return ret;
    }
};
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        
        if (nums.size() < 4) {
            return answer;
        }
        
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size() - 3 ; i++) {
            for(int j = i + 1 ; j < nums.size() - 2 ; j++) {
                long long remain = (long long)target - nums[i] - nums[j];
                
                int start = j + 1;
                int end = nums.size() - 1;
                
                while (start < end) {
                    if (remain == nums[start] + nums[end]) {
                        answer.push_back({nums[i], nums[j], nums[start++], nums[end--]});
                        
                        while(start < end && nums[start] == nums[start-1]) start++;
                        while(start < end && nums[end] == nums[end+1]) end--;
                    } else if (remain > nums[start] + nums[end]) {
                        start++;
                    } else { // remain < nums[start] + nums[end]
                        end--;
                    }
                }
                
                while(j + 1 < nums.size() && nums[j] == nums[j+1]) j++;
            }
            
            while(i + 1 < nums.size() && nums[i] == nums[i+1]) i++;
        }
        
        return answer;
    }
};
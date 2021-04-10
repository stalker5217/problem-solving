#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = 987654321;
        int closestDiff = 987654321;
        
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < nums.size() - 2 ; i++){    
            int start = i+1;
            int end = nums.size() - 1;
            
            while(start < end){
                int sum = nums[i] + nums[start] + nums[end];
                
                int curDiff = sum - target;
                
                if(abs(curDiff) < closestDiff){
                    closestDiff = abs(curDiff);
                    ret = sum;
                }
                
                if(curDiff <= 0) start++;
                else end--;
            }
        }
        
        return ret;
    }
};
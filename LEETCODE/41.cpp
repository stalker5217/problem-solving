#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        auto startIter = lower_bound(nums.begin(), nums.end(), 1);
        if(startIter == nums.end() || *startIter > 1) return 1;

        for(auto iter = startIter ; iter != (nums.end() - 1) ; iter++){
            if(*(iter + 1) - *(iter) > 1) return (*iter) + 1;
        }
        
        return nums[nums.size() - 1] + 1;
    }
};
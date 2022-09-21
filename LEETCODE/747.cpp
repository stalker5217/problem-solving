#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxIndex = max_element(nums.begin(), nums.end()) - nums.begin();
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return a > b;
        });
        
        if (nums[0] >= nums[1] * 2) {
            return maxIndex;
        }
        
        return -1;
    }
};
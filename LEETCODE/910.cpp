#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int answer = nums[nums.size() - 1] - nums[0];
        for(int i = 1 ; i < nums.size() ; i++) {
            int mmax = max(nums[i-1] + k, nums[nums.size()-1] - k);
            int mmin = min(nums[i] - k, nums[0] + k);
            answer = min(mmax - mmin, answer);
        }
        
        return answer;
    }
};
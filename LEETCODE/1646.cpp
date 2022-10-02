#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        else if (n == 1) return 1;
        
        vector<int> nums(n + 1, 0);
        nums[1] = 1;
        
        for(int i = 2 ; i <= n ; i++) {
            if (i % 2) {
                int half = (i - 1) / 2;
                nums[i] = nums[half] + nums[half + 1];
            } else {
                int half = i / 2;
                nums[i] = nums[half];
            }
        }
        
        return *max_element(nums.begin(), nums.end());
    }
};
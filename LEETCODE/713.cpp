#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int product = 1;
        int answer = 0;
        while(right < nums.size()) {
            product *= nums[right++];
            while (product >= k && left < right) {
                product /= nums[left++];
            }
            
            if (product < k) answer += right - left;
        }
        
        return answer;
    }
};
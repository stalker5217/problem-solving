#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> accumulate(nums.size(), 0);
        accumulate[0] = nums[0];
        for(int i = 1 ; i < accumulate.size() ; i++) {
            accumulate[i] = accumulate[i - 1] + nums[i];
        }
        
        
        for (int pivot = 0 ; pivot < nums.size() ; pivot++) {
            int leftSum = pivot > 0 ? accumulate[pivot - 1] : 0;
            int rightSum = accumulate[accumulate.size() - 1] - accumulate[pivot];
            
            if (leftSum == rightSum) {
                return pivot;
            }
        }
        
        return -1;
    }
};
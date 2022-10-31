#include <vector>

using namespace std;

class Solution {
public:
    /**
     * Insertion Sort
     */
    vector<int> sortArray(vector<int>& nums) {
        for(int i = 1 ; i < nums.size() ; i++) {
            for(int j = i - 1 ; j >= 0 ; j--) {
                if (nums[j] > nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                } else {
                    break;
                }
            }
        }
        
        return nums;
    }
};
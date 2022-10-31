#include <vector>

using namespace std;

class Solution {
public:
    /**
     * Bubble Sort
     */
    vector<int> sortArray(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() - 1 ; i++) {
            for (int j = 0 ; j < nums.size() - 1 ; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        
        return nums;
    }
};
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * Selection Sort
     */
    vector<int> sortArray(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() - 1 ; i++) {
            int priorityIndex = i;
            for (int j = i + 1 ; j < nums.size() ; j++) {
                if (nums[priorityIndex] > nums[j]) {
                    priorityIndex = j;
                }
            }
            
            swap(nums[priorityIndex], nums[i]);
        }
        
        return nums;
    }
};
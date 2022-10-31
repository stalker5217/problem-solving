#include <vector>

using namespace std;

class Solution {
private:
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1 , right);
            
            mergeArea(nums, left, mid, right);
        }
    }
    
    void mergeArea(vector<int>& nums, int left, int mid, int right) {
        int index1 = left;
        int index2 = mid + 1;
        
        vector<int> result;
        
        while (index1 <= mid && index2 <= right) {
            if (nums[index1] <= nums[index2]) {
                result.push_back(nums[index1++]);
            } else {
                result.push_back(nums[index2++]);
            }
        }
        
        while (index1 <= mid) {
            result.push_back(nums[index1++]);
        }
        
        while (index2 <= right) {
            result.push_back(nums[index2++]);
        }
        
        for(int i = left ; i <= right ; i++) {
            nums[i] = result[i - left];
        }
    }
    
public:
    /**
     * Merge Sort
     */
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
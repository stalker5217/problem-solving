#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower = lowerBound(nums, target);
        int upper = upperBound(nums, target);
        
        if(lower == nums.size() || nums[lower] != target) return vector<int>{-1, -1};
        else return vector<int>{lower, upper - 1};
    }
    
    int lowerBound(vector<int>& nums, const int& target) {
        int start = 0;
        int end = nums.size();
        
        while(start < end) {
            int mid = (start + end) / 2;
            if(nums[mid] >= target) end = mid;
            else start = mid + 1;
        }
        
        return end;
    }
    
    int upperBound(vector<int>& nums, const int& target) {
        int start = 0;
        int end = nums.size();
        
        while(start < end) {
            int mid = (start + end) / 2;
            if(nums[mid] > target) end = mid;
            else start = mid + 1;
        }
        
        return end;
    }
};
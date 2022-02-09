#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> partialSum;
public:
    NumArray(vector<int>& nums) 
    : partialSum(nums.size(), 0)
    {
        partialSum[0] = nums[0];
        for(int i = 1 ; i < nums.size() ; i++) {
            partialSum[i] = partialSum[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return partialSum[right];
        
        return partialSum[right] - partialSum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
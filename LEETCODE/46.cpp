#include <vector>

using namespace std;

class Solution {

private:
    vector<vector<int> > ret;
    
public:
    vector<vector<int> > permute(vector<int>& nums) {
        helper(nums, 0);
        return ret;
    }
    
    void helper(vector<int>& nums, int idx){
        if(idx == nums.size()){
            ret.push_back(nums);
            return;
        }
        
        for(int i = idx ; i < nums.size() ; i++){
            swap(nums[idx], nums[i]);
            helper(nums, idx + 1);
            swap(nums[idx], nums[i]);
        }
    }
};
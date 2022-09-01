#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<bool> exists(nums.size() + 1, false);
        
        int duplicate;
        for(int i = 0 ; i < n ; i++) {
            if (exists[nums[i]]) {
                duplicate = nums[i];
            } else {
                exists[nums[i]] = true;
            }
        }
        
        int missing;
        for(int i = 1 ; i<= n ; i++) {
            if (!exists[i]) {
                missing = i;
            }
        }
        
        vector<int> answer(2);
        answer[0] = duplicate;
        answer[1] = missing;
        
        return answer;
    }
};
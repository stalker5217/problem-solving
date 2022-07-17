#include <vector>

using namespace std;
 
 class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> exists(nums.size() + 1, 0);
        for(int num : nums) {
            exists[num] = true;
        }
        
        vector<int> answer;
        for(int i = 1 ; i <= nums.size() ; i++) {
            if (!exists[i]) {
                answer.push_back(i);
            }
        }
        
        return answer;
    }
};
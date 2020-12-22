#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> answer;
        for(int num : nums){
            if(num != val){
                answer.push_back(num);
            }
        }
        
        nums = answer;
        return nums.size();
    }
};
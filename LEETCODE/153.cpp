#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int answer = nums[0];
        for(int i = 0 ; i < nums.size() - 1 ; i++) {
            if(nums[i] > nums[i + 1]) {
                answer = nums[i + 1];
                break;
            }
        }
        
        return answer;
    }
};
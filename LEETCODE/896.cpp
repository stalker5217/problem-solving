#include <vector>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int type = 0;
        for(int i = 0 ; i < nums.size() - 1 ; i++) {
            if (type == 0) {
                if (nums[i] < nums[i + 1]) type = 1;
                else if (nums[i] > nums[i + 1]) type = -1;
            }
            else if (type == 1) {
                if (nums[i] > nums[i + 1]) return false;
            }
            else if (type == -1) {
                if (nums[i] < nums[i + 1]) return false;
            }
        }
        
        return true;
    }
};
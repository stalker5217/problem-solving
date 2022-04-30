#include <vector>

using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool isNegative = false;
        
        for(int cur : nums) {
            if (cur == 0) return 0;
            if (cur < 0) isNegative ^= 1;
        }
        
        return isNegative ? -1 : 1;
    }
};
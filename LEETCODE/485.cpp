#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen = 0;
        int cnt = 0;
        
        for(int num : nums) {
            if(num == 1) cnt++;
            else cnt = 0;
            
            maxLen = max(maxLen, cnt);
        }
        
        return maxLen;
    }
};
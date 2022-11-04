#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt(3);
        for(int num : nums) {
            if (num == 0) {
                cnt[0]++;
            } else if (num == 1) {
                cnt[1]++;
            } else {
                cnt[2]++;
            }
        }
        
        int index = 0;
        while(cnt[0]--) {
            nums[index++] = 0;
        }
        while(cnt[1]--) {
            nums[index++] = 1;
        }
        while(cnt[2]--) {
            nums[index++] = 2;
        }
    }
};